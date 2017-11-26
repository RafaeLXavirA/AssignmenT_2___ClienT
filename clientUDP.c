#include <sys/socket.h>
#include <stdlib.h>
#include <sys/types.h>
#include <netdb.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <arpa/inet.h>
#include <err.h>
#include <stdio.h>
#include <string.h>
#include <sysexits.h>
#include <sys/stat.h>
#include <netinet/in_systm.h>

int main(int argc, char *argv[])
{
	int sockfd,rc;
	struct protoent *p;
	struct sockaddr_in sin;
	struct ip pkt_hdr;

	if(argc !=2)
		errx(EX_USAGE, "%s addr", argv[0]);
			memset(&sin,0,sizeof(sin));
			sin.sin_family = AF_INET;
			sin.sin_port = 0;

	if(inet_pton(AF_INET, argv[1], &sin.sin_addr)<=0)
		err(EX_USAGE,"Parse address");

	p = getprotobyname("udp");

		if(p == NULL)
			err(EX_UNAVAILABLE, "getprotobyname");

			sockfd = socket(AF_INET, SOCK_RAW, p->p_proto);

			if(sockfd < 0)
				err(EX_OSERR,"socket");

			memset(&pkt_hdr,0,sizeof(pkt_hdr));

	pkt_hdr.ip_hl = 0x5;
	pkt_hdr.ip_v = 0x4;
	pkt_hdr.ip_tos = 0x0;
	pkt_hdr.ip_len = 20;
	pkt_hdr.ip_id = 12830;
	pkt_hdr.ip_off = 0x0;
	pkt_hdr.ip_ttl = 64;
	pkt_hdr.ip_p = IPPROTO_RAW;
	pkt_hdr.ip_sum = 0x0;

	while(1)
	{
		rc = sendto(sockfd, &pkt_hdr, sizeof(pkt_hdr), 0, (struct sockaddr *)&sin, sizeof(sin));
		printf("wrote %d bytes\n", rc);
	}
	return 0;
}
