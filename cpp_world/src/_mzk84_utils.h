#include "_includes.h"

namespace mzk84_utils {

inline std::string ltrim(const std::string& str, const std::string& exclude_set) {
	size_t pos = 0;
	while (pos < str.size() && exclude_set.find(str[pos]) != std::string::npos)
		pos++;
	return str.substr(pos);
}

inline std::string rtrim(const std::string& str, const std::string& exclude_set) {
	size_t pos = str.size();
	while (pos > 0 && exclude_set.find(str[pos - 1]) != std::string::npos)
		pos--;
	return str.substr(0, pos);
}

inline std::string lrtrim(const std::string& str, const std::string& exclude_set) {
	std::string lstr = ltrim(str, exclude_set);
	return rtrim(lstr, exclude_set);
}

inline std::string lrtrim(const std::string& str) {
	const std::string exclude_set("\n", 1);
	return lrtrim(str, exclude_set);
}

inline void split_string_by_space(const std::string& str, std::vector<std::string>& output) {
	std::string::size_type len = str.length();
	std::string::size_type start = str.find_first_not_of(' ');
	std::string::size_type stop;

	while ((start != std::string::npos) && (start < len)) {
		stop = str.find_first_of(' ', start);
		if ((stop == std::string::npos) || (stop > len))
			stop = len;
		output.emplace_back(lrtrim(str.substr(start, stop - start)));
		start = str.find_first_not_of(' ', stop + 1);
	}
}

inline std::string to_hex_string(const unsigned char* str, size_t length) {
	std::ostringstream os;
	os.fill('0');
	os << std::hex;
	for (const unsigned char* c = str; c < str + length; ++c)
		os << std::setw(2) << (unsigned int)*c;

	return os.str();
}

inline std::string get_random_string(size_t length) {
	// Pick chars from ASCII range of printable chars
	thread_local static std::default_random_engine generator{ std::random_device{}() };
	thread_local static std::uniform_int_distribution<size_t> distribution(33, 126);
	std::string s;
	s.reserve(length);
	while (length--)
		s += (unsigned char)distribution(generator);

	return s;
}

inline size_t get_random_number(size_t begin, size_t end) {
	thread_local static std::default_random_engine generator{ std::random_device{}() };
	thread_local static std::uniform_int_distribution<size_t> distribution(begin, end);
	return distribution(generator);
}

inline void get_random_numbers(size_t begin, size_t end, size_t amount, size_t* out) {
	thread_local static std::default_random_engine generator{ std::random_device{}() };
	thread_local static std::uniform_int_distribution<size_t> distribution(begin, end);
	for (size_t i = 0; i < amount; ++i)
		*(out + i) = distribution(generator);
}

inline std::string format_duration(const std::chrono::nanoseconds& dur) {
	std::chrono::nanoseconds dur_l = dur;
	std::ostringstream os;
	os.fill('0');
	auto d = std::chrono::duration_cast<std::chrono::duration<int, std::ratio<86400>>>(dur_l);
	dur_l -= d;
	auto h = std::chrono::duration_cast<std::chrono::hours>(dur_l);
	dur_l -= h;
	auto m = std::chrono::duration_cast<std::chrono::minutes>(dur_l);
	dur_l -= m;
	auto s = std::chrono::duration_cast<std::chrono::seconds>(dur_l);
	dur_l -= s;
	auto ms = std::chrono::duration_cast<std::chrono::milliseconds>(dur_l);
	if (d.count() > 0)
		os << std::setw(2) << d.count() << " d, ";
	if (h.count() > 0)
		os << std::setw(2) << h.count() << " h, ";
	if (m.count() > 0)
		os << std::setw(2) << m.count() << " m, ";
	if (s.count() > 0)
		os << std::setw(2) << s.count() << " s, ";
	if (ms.count() > 0)
		os << std::setw(2) << ms.count() << " ms";
	return os.str();
}

} // namespace mzk84_utils
