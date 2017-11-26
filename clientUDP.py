import socket, sys
from struct import *

source_ip = '192.168.252.130'
dest_ip = '192.168.101.130'

try:
    s = socket.socket(socket.AF_INET, socket.SOCK_RAW, socket.IPPROTO_UDP)

except socket.error , msg:
    print 'Socket could not be created. Error Code : ' + str(msg[0]) + 'Message' + msg[1]
    sys.exit()

    packet = '';

ip_ihl = 5
ip_ver = 4
ip_tos = 0
ip_tot_len = 0
ip_id = 54321
ip_frag_off = 0
ip_ttl = 225
ip_proto = socket.IPPROTO_UDP
ip_check = 0
ip_saddr = socket.inet_aton ( source_ip )
ip_daddr = socket.inet_aton ( dest ip )
ip_header = pack('!BBHHHBBH4s4s' , ip_ihl_ver, ip_tos, ip_tot_len, ip_id, ip_frag_off, ip_ttl, ip_proto, ip_check, ip_saddr, ip_daddr)
ip_ihl_ver = (4  <<  4) | 5
ip_proto, ip_check, ip_saddr, ip_daddr)

source_address = socket.inet_aton( source_ip )
dest_address = socket.inet_aton( dest_ip )

placeholder = 0

protocol = socket.IPPROTO_UDP

length = len(user_data)
psh = pack('!4s4sBBH' , source_address , dest_address , placeholder , protocol , length);
psh = psh + user_data;

packet = ip_header + user_data

var = 1

while var == 1;
    s.sendto(packet, (dest_ip , 0))
    print "Sending",(s.sendto(packet,(dest_ip,0))),"bytes"
