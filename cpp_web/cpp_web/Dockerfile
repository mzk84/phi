FROM cpp_web_box

WORKDIR /usr/cpp_web

COPY . .

WORKDIR /usr/cpp_web/build
RUN cmake .
RUN make

CMD ["./cpp_web"]
