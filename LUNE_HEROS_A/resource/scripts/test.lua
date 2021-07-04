http = require("socket.http")
content, statuscode, response_header = http.request("http://somedomain.com/download.php", "a=1")
print(statuscode)