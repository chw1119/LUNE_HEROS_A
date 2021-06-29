const net = require('net');
const { off } = require('process');

const server = net.createServer(function(client){

    console.log("CLIENT CONNECTED");

    client.write("SERVER SEND : HELLO");
    
    client.on("data", function(data){
        console.log(data + " 받음");
        
    });
    
    client.on("end", function(){
        
    });

});

server.listen(8080);

/* packet dev */

const PACKET_ID_LOGIN = 0;
const PACKET_ID_ACCEPTLOGIN = 1;

const Packet = class {
    constructor(packetId,contentsLength){

        this.packetId = packetId;
        this.buffer = Buffer.alloc(contentsLength + 0x4 || 0xff);

    }

    getPacketId(){
        return this.packetId;
    }

    getBuffer(){
        return this.buffer;
    }

    getPacketLength(){
        this.setOffset(0);

        return this.buffer.readInt16LE();
    }

    getPacketEmpty(){
        this.setOffset(2);
        return this.buffer.readInt8();
    }

    getPacketId(){
        this.setOffset(3);
        return this.buffer.readInt8();
    }

    setOffset(offset){
        this.buffer.offset(offset);
    }
}


const ItemPacket = class extends Packet {
    
}

const LoginPacket = class extends Packet {

    constructor(){

    }
}

const AcceptPacket = class extends Packet {

}

const DeniedPacket = class extends Packet {
    constructor(deniedReson){
        this.reason = deniedReson;

    }
}

/*
endian little - c++

short lengthOfPacket 

byte empty

byte packetId -> 0~255

//4byte align

~~~~~~ packet Information
*/

/*

login packet id = 0

content

user 고유 key
char [12]

accept Packet id = 1
content

byte ra key

byte messageLength

char[messageLength]

denied Packet id = 2
content

byte messageLength

char[messageLength]


*/