#ifndef __14229_DEF_H__
#define __14229_DEF_H__
/**
 *@������UDS����Ӧ��
 *
 */

typedef enum {
	/**0x00 ��Ӧ��ʹ��*/
	
	/**�ܾ�����*/
	NRC_GR = 0x10,
	
	/**����֧��*/
	NRC_SNS = 0x11,
	
	/**�ӹ��ܲ�֧�� */
	NRC_SFNS = 0x12,
	
	/**���ĳ��ȴ�����߸�ʽ�Ƿ�*/
	NRC_IMLOIF = 0x13,
	
	/**��������Ӧ���������Э������*/
	NRC_RTL = 0x14,
	
	/**0x15 - 0x20 ISO/SAE����*/

	/**��������ʱæ�����������ظ�*/
	NRC_BRR = 0x21,
	
	/**����������*/
	NRC_CNC = 0x22,
	
	/**0x23 ISO*/
	
	/**����˳�����*/
	NRC_RSE = 0x24,
	
	/**�����粿��û����Ӧ */
	NRC_NRFSC = 0x25,
	
	/**���ڷ��������Ҹù��Ͻ�ֹ������ִ������Ķ��� */
	NRC_FPEORA = 0x26,
	
	/**0x27 - 0x30 ISO/SAE����*/
	
	/**���󳬳���Χ*/
	NRC_POOR = 0x31,
	
	/**0x32 ISO/SAE����*/
	
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