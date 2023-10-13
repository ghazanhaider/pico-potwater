#define USER_AGENT "pico/1"

/* Simple HTTP POST header */
#define HTTP_POST_TEMPLATE "POST %s HTTP/1.1\r\n"	\
	"Host: %s\r\n"									\
    "User-Agent: %s\r\n"							\
	"Authorization: Token %s\r\n"					\
    "Accept: */*\r\n"								\
	"Content-Length: %d\r\n"						\
    "Connection: Close\r\n"							\
    "\r\n"

#define HTTP_POST_FORMAT(payload_len) HTTP_POST_TEMPLATE, REMOTE_URL, REMOTE_HOST, USER_AGENT, AUTH_TOKEN, payload_len
