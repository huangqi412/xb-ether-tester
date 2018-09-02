/* 
 * ������Ϊ��ѡ���Դ������
 * �������İ�Ȩ(����Դ�뼰�����Ʒ����汾)��һ�й������С�
 * ����������ʹ�á�������������
 * ��Ҳ�������κ���ʽ���κ�Ŀ��ʹ�ñ�����(����Դ�뼰�����Ʒ����汾)���������κΰ�Ȩ���ơ�
 * =====================
 * ����: ������
 * ����: sunmingbao@126.com
 */

#include "global_info.h"

static unsigned char ping_req[]={
0x00, 0x23, 0xcd, 0x76, 0x63, 0x1a, 0x00 ,0x21 ,0x85 ,0xc5 ,0x2b ,0x8f ,0x08 ,0x00 ,0x45 ,0x00,
0x00, 0x3c, 0x79, 0x19, 0x00, 0x00, 0x40 ,0x01 ,0x7f ,0xf2 ,0xc0 ,0xa8 ,0x01 ,0x64 ,0xc0 ,0xa8,
0x01, 0x01, 0x08, 0x00, 0x44, 0x5c, 0x04 ,0x00 ,0x05 ,0x00 ,0x61 ,0x62 ,0x63 ,0x64 ,0x65 ,0x66,
0x67, 0x68, 0x69, 0x6a, 0x6b, 0x6c, 0x6d ,0x6e ,0x6f ,0x70 ,0x71 ,0x72 ,0x73 ,0x74 ,0x75 ,0x76,
0x77, 0x61, 0x62, 0x63, 0x64, 0x65, 0x66 ,0x67 ,0x68 ,0x69  
		
	};

static unsigned char ping_reply[ ]={
0x00, 0x21, 0x85, 0xc5, 0x2b, 0x8f, 0x00, 0x23, 0xcd, 0x76, 0x63, 0x1a, 0x08, 0x00, 0x45, 0x00, 
0x00, 0x3c, 0x00, 0x91, 0x00, 0x00, 0x40, 0x01, 0xf6, 0x7a, 0xc0, 0xa8, 0x01, 0x01, 0xc0, 0xa8, 
0x01, 0x64, 0x00, 0x00, 0x4c, 0x5c, 0x04, 0x00, 0x05, 0x00, 0x61, 0x62, 0x63, 0x64, 0x65, 0x66, 
0x67, 0x68, 0x69, 0x6a, 0x6b, 0x6c, 0x6d, 0x6e, 0x6f, 0x70, 0x71, 0x72, 0x73, 0x74, 0x75, 0x76, 
0x77, 0x61, 0x62, 0x63, 0x64, 0x65, 0x66, 0x67, 0x68, 0x69, 
};
static unsigned char arp_req[ ]={
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x00, 0x21, 0x85, 0xc5, 0x2b, 0x8f, 0x08, 0x06, 0x00, 0x01, 
0x08, 0x00, 0x06, 0x04, 0x00, 0x01, 0x00, 0x21, 0x85, 0xc5, 0x2b, 0x8f, 0xc0, 0xa8, 0x01, 0x64, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xc0, 0xa8, 0x01, 0x01, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xff, 0x00, 0x23, 0xcd, 0x76, 0x63, 0x1a, 0x08, 0x06, 0x00, 0x01, 
};

static unsigned char arp_reply[ ]={
0x00, 0x21, 0x85, 0xc5, 0x2b, 0x8f, 0x00, 0x23, 0xcd, 0x76, 0x63, 0x1a, 0x08, 0x06, 0x00, 0x01, 
0x08, 0x00, 0x06, 0x04, 0x00, 0x02, 0x00, 0x23, 0xcd, 0x76, 0x63, 0x1a, 0xc0, 0xa8, 0x01, 0x01, 
0x00, 0x21, 0x85, 0xc5, 0x2b, 0x8f, 0xc0, 0xa8, 0x01, 0x64, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xff, 0x00, 0x23, 0xcd, 0x76, 0x63, 0x1a, 0x08, 0x06, 0x00, 0x01, 
};

static unsigned char tcp_syn[ ]={
0x00, 0x23, 0xcd, 0x76, 0x63, 0x1a, 0x00, 0x21, 0x85, 0xc5, 0x2b, 0x8f, 0x08, 0x00, 0x45, 0x00, 
0x00, 0x34, 0x0a, 0x27, 0x40, 0x00, 0x40, 0x06, 0xd2, 0xca, 0xc0, 0xa8, 0x01, 0x64, 0x71, 0x6b, 
0x2a, 0x5b, 0x05, 0x05, 0x00, 0x50, 0x7a, 0x77, 0xff, 0x4b, 0x00, 0x00, 0x00, 0x00, 0x80, 0x02, 
0xff, 0xff, 0x80, 0x16, 0x00, 0x00, 0x02, 0x04, 0x17, 0xca, 0x01, 0x03, 0x03, 0x01, 0x01, 0x01, 
0x04, 0x02, 
};

static unsigned char udp[ ]={
0x00, 0x23, 0xcd, 0x76, 0x63, 0x1a, 0x00, 0x21, 0x85, 0xc5, 0x2b, 0x8f, 0x08, 0x00, 0x45, 0x00, 
0x00, 0x30, 0x21, 0xb3, 0x00, 0x00, 0x40, 0x11, 0x9d, 0x6f, 0xc0, 0xa8, 0x01, 0x64, 0xde, 0x49, 
0x1b, 0x45, 0x05, 0x21, 0x27, 0x15, 0x00, 0x1c, 0x12, 0x8b, 0xef, 0xec, 0x3d, 0xd6, 0xc5, 0x36, 
0x44, 0x67, 0x39, 0x21, 0xbc, 0x64, 0x6d, 0xb3, 0x97, 0xc8, 0x82, 0xb5, 0x50, 0x41, 
};

static unsigned char arp6_req[ ]={
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x00, 0x21, 0x85, 0xc5, 0x2b, 0x8f, 0x08, 0x06, 0x00, 0x01, 
0x08, 0x00, 0x06, 0x10, 0x00, 0x01, 0x00, 0x21, 0x85, 0xc5, 0x2b, 0x8f, 0xc0, 0xa8, 0x01, 0x64, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xc0, 0xa8, 0x01, 0x01, 0x61, 0x62, 0x00, 0x21, 0x85, 0xc5, 
0x2b, 0x8f, 0x69, 0x6a, 0x6b, 0x6c, 0x6d, 0x6e, 0x6f, 0x70, 0x71, 0x72, 0x73, 0x74, 0x75, 0x76, 
0x77, 0x61, 
};

static unsigned char arp6_reply[ ]={
0x00, 0x21, 0x85, 0xc5, 0x2b, 0x8f, 0x00, 0x23, 0xcd, 0x76, 0x63, 0x1a, 0x08, 0x06, 0x00, 0x01, 
0x08, 0x00, 0x06, 0x10, 0x00, 0x02, 0x00, 0x23, 0xcd, 0x76, 0x63, 0x1a, 0xc0, 0xa8, 0x01, 0x01, 
0x00, 0x21, 0x85, 0xc5, 0x2b, 0x8f, 0xc0, 0xa8, 0x01, 0x64, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xff, 0x00, 0x23, 0xcd, 0x76, 0x63, 0x1a, 0x08, 0x06, 0x00, 0x01, 0x73, 0x74, 0x75, 0x76, 
0x77, 0x61, 
};

static unsigned char nd_req[ ]={
0x33, 0x33, 0xff, 0x00, 0x01, 0x57, 0x00, 0x0c, 0x29, 0x33, 0x3d, 0x0a, 0x86, 0xdd, 0x60, 0x00, 
0x00, 0x00, 0x00, 0x20, 0x3a, 0xff, 0x20, 0x01, 0x20, 0x01, 0x20, 0x01, 0x20, 0x01, 0x20, 0x01, 
0x00, 0x00, 0x00, 0x00, 0x01, 0x58, 0xff, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x01, 0xff, 0x00, 0x01, 0x57, 0x87, 0x00, 0xcf, 0x44, 0x00, 0x00, 0x00, 0x00, 0x20, 0x01, 
0x20, 0x01, 0x20, 0x01, 0x20, 0x01, 0x20, 0x01, 0x00, 0x00, 0x00, 0x00, 0x01, 0x57, 0x01, 0x01, 
0x00, 0x0c, 0x29, 0x33, 0x3d, 0x0a, 
};

static unsigned char nd_reply[ ]={
0x00, 0x0c, 0x29, 0x33, 0x3d, 0x0a, 0x00, 0x21, 0x85, 0xc5, 0x2b, 0x8f, 0x86, 0xdd, 0x60, 0x00, 
0x00, 0x00, 0x00, 0x20, 0x3a, 0xff, 0x20, 0x01, 0x20, 0x01, 0x20, 0x01, 0x20, 0x01, 0x20, 0x01, 
0x00, 0x00, 0x00, 0x00, 0x01, 0x57, 0x20, 0x01, 0x20, 0x01, 0x20, 0x01, 0x20, 0x01, 0x20, 0x01, 
0x00, 0x00, 0x00, 0x00, 0x01, 0x58, 0x88, 0x00, 0x80, 0x17, 0x60, 0x00, 0x00, 0x00, 0x20, 0x01, 
0x20, 0x01, 0x20, 0x01, 0x20, 0x01, 0x20, 0x01, 0x00, 0x00, 0x00, 0x00, 0x01, 0x57, 0x02, 0x01, 
0x00, 0x21, 0x85, 0xc5, 0x2b, 0x8f, 
};

static unsigned char ping_req_ipv6[]={
0x00, 0x21, 0x85, 0xc5, 0x2b, 0x8f, 0x00, 0x0c, 0x29, 0x33, 0x3d, 0x0a, 0x86, 0xdd, 0x60, 0x00, 
0x00, 0x00, 0x00, 0x40, 0x3a, 0x40, 0x20, 0x01, 0x20, 0x01, 0x20, 0x01, 0x20, 0x01, 0x20, 0x01, 
0x00, 0x00, 0x00, 0x00, 0x01, 0x58, 0x20, 0x01, 0x20, 0x01, 0x20, 0x01, 0x20, 0x01, 0x20, 0x01, 
0x00, 0x00, 0x00, 0x00, 0x01, 0x57, 0x80, 0x00, 0x89, 0xb8, 0x53, 0x11, 0x00, 0x01, 0xba, 0xff, 
0x22, 0x56, 0x89, 0xa7, 0x0e, 0x00, 0x08, 0x09, 0x0a, 0x0b, 0x0c, 0x0d, 0x0e, 0x0f, 0x10, 0x11, 
0x12, 0x13, 0x14, 0x15, 0x16, 0x17, 0x18, 0x19, 0x1a, 0x1b, 0x1c, 0x1d, 0x1e, 0x1f, 0x20, 0x21, 
0x22, 0x23, 0x24, 0x25, 0x26, 0x27, 0x28, 0x29, 0x2a, 0x2b, 0x2c, 0x2d, 0x2e, 0x2f, 0x30, 0x31, 
0x32, 0x33, 0x34, 0x35, 0x36, 0x37, 
		
	};

static unsigned char ping_reply_ipv6[ ]={
0x00, 0x0c, 0x29, 0x33, 0x3d, 0x0a, 0x00, 0x21, 0x85, 0xc5, 0x2b, 0x8f, 0x86, 0xdd, 0x60, 0x00, 
0x00, 0x00, 0x00, 0x40, 0x3a, 0x80, 0x20, 0x01, 0x20, 0x01, 0x20, 0x01, 0x20, 0x01, 0x20, 0x01, 
0x00, 0x00, 0x00, 0x00, 0x01, 0x57, 0x20, 0x01, 0x20, 0x01, 0x20, 0x01, 0x20, 0x01, 0x20, 0x01, 
0x00, 0x00, 0x00, 0x00, 0x01, 0x58, 0x81, 0x00, 0x88, 0xb8, 0x53, 0x11, 0x00, 0x01, 0xba, 0xff, 
0x22, 0x56, 0x89, 0xa7, 0x0e, 0x00, 0x08, 0x09, 0x0a, 0x0b, 0x0c, 0x0d, 0x0e, 0x0f, 0x10, 0x11, 
0x12, 0x13, 0x14, 0x15, 0x16, 0x17, 0x18, 0x19, 0x1a, 0x1b, 0x1c, 0x1d, 0x1e, 0x1f, 0x20, 0x21, 
0x22, 0x23, 0x24, 0x25, 0x26, 0x27, 0x28, 0x29, 0x2a, 0x2b, 0x2c, 0x2d, 0x2e, 0x2f, 0x30, 0x31, 
0x32, 0x33, 0x34, 0x35, 0x36, 0x37, 
};

t_sample_pkt gat_sample_pkts[] = 
{
    {ping_req, sizeof(ping_req)},
    {ping_reply, sizeof(ping_reply)},
    {arp_req, sizeof(arp_req)},
    {arp_reply, sizeof(arp_reply)},
    {tcp_syn, sizeof(tcp_syn)},
    {udp, sizeof(udp)},
    {arp6_req, sizeof(arp6_req)},
    {arp6_reply, sizeof(arp6_reply)},
    {nd_req, sizeof(nd_req)},
    {nd_reply, sizeof(nd_reply)},
    {ping_req_ipv6, sizeof(ping_req_ipv6)},
    {ping_reply_ipv6, sizeof(ping_reply_ipv6)},
};

