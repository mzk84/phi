#include "PoW_SHA1.h"
#include "_mzk84_utils.h"

// Proof of Work (PoW)
// Find the suffix to the given string where SHA1 checksum of the entire string begins with number of zeroes equal to the given difficulty

// Some definitions
#define SHA1_LEN 20
#define MAX_SUFFIX_LEN 26 // max. difficulty (9) + max. thread index (7)

// Global variables
std::condition_variable g_condvar;
std::mutex g_mutex;
std::atomic_bool g_found;
bool gg_found;
std::string g_suffix;

// Solution 1 - small memory usage, random string generation with each attempt
void worker_1(const std::string& prefix, size_t difficulty, SHA_CTX* ctx, size_t thread_idx) {
	SHA_CTX worker_ctx;
	unsigned int h0, h1;
	unsigned char md[SHA1_LEN];
	unsigned char suffix[MAX_SUFFIX_LEN] = { 0 };
	
	// Variations: suffix_len = difficulty + thread_idx, or similar...
	size_t suffix_len = difficulty;

	// Choose chars from ASCII printable subset
	std::default_random_engine generator{ std::random_device{}() };
	std::uniform_int_distribution<size_t> distribution(33, 126);

	while (!g_found.load(std::memory_order_acquire)) {
		// Generate next suffix candidate
		for (size_t i = 0; i < suffix_len; ++i)
			suffix[i] = (unsigned char)distribution(generator);

		memcpy(&worker_ctx, ctx, sizeof(SHA_CTX));
		SHA1_Update(&worker_ctx, &suffix, suffix_len);
		SHA1_Final(md, &worker_ctx);

		h0 = worker_ctx.h0;
		h1 = worker_ctx.h1;

		// Accepts up to 9 leading zeroes - difficulties 1 to 9
		bool condition = (difficulty < 9) ? !(h0 >> ((8 - difficulty) * 4)) : (!h0 && !(h1 >> 28));

		if (condition) {
			// Found solution!
			std::string suffix_str(suffix, suffix + suffix_len);
			std::string entire_str = prefix + suffix_str;
			std::string hex_str = mzk84_utils::to_hex_string(md, SHA1_LEN);
			{
				std::lock_guard<std::mutex> lg(g_mutex);
				g_found.store(true, std::memory_order_release);
				gg_found = true;
				g_suffix = suffix_str;
				std::cout << "Suffix:       " << suffix_str << "\n";
				std::cout << "Entire input: " << entire_str << "\n";
				std::cout << "SHA1:         " << hex_str << "\n";
				std::cout << "Thread ID:    " << thread_idx << "\n";
			}
			g_condvar.notify_one();
			return;
		}
	}
}

// Solution 2 - random string generation at the beginning, incrementing char values with each loop, small memory usage
void worker_2(const std::string& prefix, size_t difficulty, SHA_CTX* ctx, size_t thread_idx) {
	SHA_CTX worker_ctx;
	unsigned int h0, h1;
	unsigned char md[SHA1_LEN];
	unsigned char suffix[MAX_SUFFIX_LEN] = { 0 };
	size_t suffix_len = difficulty + thread_idx;

	// Choose chars from ASCII printable subset
	std::default_random_engine generator{ std::random_device{}() };
	std::uniform_int_distribution<size_t> distribution(33, 126);
	for (size_t i = 0; i < suffix_len; ++i)
		suffix[i] = (unsigned char)distribution(generator);

	size_t pos = 0;
	while (!g_found.load(std::memory_order_acquire)) {
		// Generate next suffix candidate - slower than generating random elements each time?
		suffix[pos]++;
		if (suffix[pos] == 127)
			suffix[pos] = 33;
		pos++;
		if (pos == MAX_SUFFIX_LEN)
			pos = 0;

		memcpy(&worker_ctx, ctx, sizeof(SHA_CTX));
		SHA1_Update(&worker_ctx, &suffix, suffix_len);
		SHA1_Final(md, &worker_ctx);

		h0 = worker_ctx.h0;
		h1 = worker_ctx.h1;

		// Accepts up to 9 leading zeroes - difficulties 1 to 9
		bool condition = (difficulty < 9) ? !(h0 >> ((8 - difficulty) * 4)) : (!h0 && !(h1 >> 28));

		if (condition) {
			// Found solution!
			std::string suffix_str(suffix, suffix + suffix_len);
			std::string entire_str = prefix + suffix_str;
			std::string hex_str = mzk84_utils::to_hex_string(md, SHA1_LEN);
			{
				std::lock_guard<std::mutex> lg(g_mutex);
				g_found.store(true, std::memory_order_release);
				gg_found = true;
				g_suffix = suffix_str;
				std::cout << "Suffix:       " << suffix_str << "\n";
				std::cout << "Entire input: " << entire_str << "\n";
				std::cout << "SHA1:         " << hex_str << "\n";
				std::cout << "Thread ID:    " << thread_idx << "\n";
			}
			g_condvar.notify_one();
			return;
		}
	}
}

// Solution 3 - Long random string as suffix buffer
void worker_3(const std::string& prefix, size_t difficulty, SHA_CTX* ctx, size_t thread_idx) {
	SHA_CTX worker_ctx;
	unsigned int h0, h1;
	unsigned char md[SHA1_LEN];
	unsigned char suffix[MAX_SUFFIX_LEN] = { 0 };
	size_t suffix_len = difficulty + thread_idx;

	std::string suffix_buff;
	size_t suffix_buff_len = 10000;
	suffix_buff.reserve(suffix_buff_len);
	size_t suffix_start_pos = 0;

	// Choose chars from ASCII printable subset
	std::default_random_engine generator{ std::random_device{}() };
	std::uniform_int_distribution<size_t> distribution(33, 126);

	while (!g_found.load(std::memory_order_acquire)) {
		
		if (suffix_start_pos == 0) {
			for (size_t i = 0; i < suffix_buff_len; ++i)
				suffix_buff[i] = (unsigned char)distribution(generator);
		}

		memcpy(&worker_ctx, ctx, sizeof(SHA_CTX));
		SHA1_Update(&worker_ctx, &suffix_buff[suffix_start_pos], suffix_len);
		SHA1_Final(md, &worker_ctx);

		h0 = worker_ctx.h0;
		h1 = worker_ctx.h1;

		// Accepts up to 9 leading zeroes - difficulties 1 to 9
		bool condition = (difficulty < 9) ? !(h0 >> ((8 - difficulty) * 4)) : (!h0 && !(h1 >> 28));

		if (condition) {
			// Found solution!
			std::string suffix_str(suffix, suffix + suffix_len);
			std::string entire_str = prefix + suffix_str;
			std::string hex_str = mzk84_utils::to_hex_string(md, SHA1_LEN);
			{
				std::lock_guard<std::mutex> lg(g_mutex);
				g_found.store(true, std::memory_order_release);
				gg_found = true;
				g_suffix = suffix_str;
				std::cout << "Suffix:       " << suffix_str << "\n";
				std::cout << "Entire input: " << entire_str << "\n";
				std::cout << "SHA1:         " << hex_str << "\n";
				std::cout << "Thread ID:    " << thread_idx << "\n";
			}
			g_condvar.notify_one();
			return;
		}

		suffix_start_pos++;
		if (suffix_start_pos == suffix_buff_len - suffix_len)
			suffix_start_pos = 0;
	}

}

std::string PoW_SHA1_Runner(const std::string& prefix, size_t difficulty, size_t worker_n) {
	g_found.store(false, std::memory_order_release);
	gg_found = false;
	size_t num_of_cpu_cores = 8;
	std::chrono::steady_clock::time_point begin, end;
	time_t tt;
	struct tm* t;
	SHA_CTX ctx;

	std::cout << "\nRunning " << num_of_cpu_cores << " worker threads.\n";
	std::cout << "Prefix is : \"" << prefix << "\". Difficulty is: " << difficulty << ".\n";

	std::time(&tt);
	t = localtime(&tt);
	std::cout << "Started at " << std::put_time(t, "%T") << "\n\n";
	begin = std::chrono::steady_clock::now();

	SHA1_Init(&ctx);
	SHA1_Update(&ctx, (const unsigned char*)prefix.data(), prefix.length());

	std::function<void(const std::string, size_t, SHA_CTX*, size_t)> worker;
	switch (worker_n)
	{
	case 1:
		worker = worker_1;
		break;
	case 2:
		worker = worker_2;
		break;
	case 3:
	default:
		worker = worker_3;
		break;
	}

	std::vector<std::thread> workers;
	for (size_t i = 0; i < num_of_cpu_cores; ++i)
		workers.emplace_back(std::thread(worker, prefix, difficulty, &ctx, i));

	std::unique_lock<std::mutex> ul(g_mutex);
	g_condvar.wait(ul, [&] { return gg_found; });

	for (auto& w : workers)
		w.join();

	end = std::chrono::steady_clock::now();
	std::time(&tt);
	t = localtime(&tt);

	std::cout << "\nFinished at " << std::put_time(t, "%T") << "\n";
	std::cout << "\nElapsed time: " << mzk84_utils::format_duration(end - begin) << "\n";

	return g_suffix;
}
