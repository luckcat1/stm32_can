#ifndef __14229_DEF_H__
#define __14229_DEF_H__
/**
 *@描述：UDS否定响应码
 *
 */

typedef enum {
	/**0x00 不应被使用*/
	
	/**拒绝服务*/
	NRC_GR = 0x10,
	
	/**服务不支持*/
	NRC_SNS = 0x11,
	
	/**子功能不支持 */
	NRC_SFNS = 0x12,
	
	/**报文长度错误或者格式非法*/
	NRC_IMLOIF = 0x13,
	
	/**服务器响应超过传输层协议限制*/
	NRC_RTL = 0x14,
	
	/**0x15 - 0x20 ISO/SAE保留*/

	/**服务器暂时忙，不能做出回复*/
	NRC_BRR = 0x21,
	
	/**条件不满足*/
	NRC_CNC = 0x22,
	
	/**0x23 ISO*/
	
	/**请求顺序错误*/
	NRC_RSE = 0x24,
	
	/**子网络部件没有响应 */
	NRC_NRFSC = 0x25,
	
	/**由于发生故障且该故障禁止服务器执行请求的动作 */
	NRC_FPEORA = 0x26,
	
	/**0x27 - 0x30 ISO/SAE保留*/
	
	/**请求超出范围*/
	NRC_POOR = 0x31,
	
	/**0x32 ISO/SAE保留*/
	
	NRC_SAD = 0x33,
	
	NRC_IK = 0x35,
	NRC_ENOA,
	NRC_RTDNE,
	NRC_UDNA =0x70,
	NRC_TDS,
	NRC_GPF,
	NRC_WBSC,
	NRC_RCRRP = 0x78,
	NRC_SFNSIAS = 0x7E,
	NRC_SNSIAS,
	NRC_RPMTH =0x81,
	NRC_RPMTL,
	NRC_EIR,
	NRC_EINR,
	NRC_ERTTL,
	NRC_TEMPTH,
	NRC_TEMPTL,
	NRC_VSTH,
	NRC_VSTL,
	NRC_TPTH,
	NRC_TPTL,
	NRC_TRNIN,
	NRC_TRNIG,
	NRC_BSNC = 0x8F,
	NRC_SLNIP = 0x90,
	NRC_TCCL = 0x91,
	NRC_VTH = 0x92,
	NRC_VTL = 0x93,
	NRC_R = 0xFF,	
}NRC_Type;




#endif