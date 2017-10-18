socket = require('socket')
io.write("ConnecT To HosT : ")
server = io.read()
io.write("ConnecT To PorT : ")
port = io.read()
client = socket.connect(server,port)

if client then
	io.write("ConnectioN To ServeR SuccesS !!\n")

	while true do
		io.write("ClienT MessagE : ")
		client:send(io.read() .. "\n")
		reply = client:receive()
		io.write(reply .. "\n")
	end
end
