var http = require('http')
var fs = require('fs'); 
port = 3000

var server = http.createServer(function(req, res) {
res.writeHead(200),{'Content-Type': 'text/html'};
var readStream = fs.createReadStream(__dirname + "index.html");
readStream.pipe(res);
});

server.listen(port);