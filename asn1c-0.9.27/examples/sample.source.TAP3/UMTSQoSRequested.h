/*
 * Generated by asn1c-0.9.28 (http://lionet.info/asn1c)
 * From ASN.1 module "TAP-0310"
 * 	found in "../tap3.asn1"
 * 	`asn1c -S ../../skeletons`
 */

#ifndef	_UMTSQoSRequested_H_
#define	_UMTSQoSRequested_H_


#include <asn_application.h>

/* Including external dependencies */
#include "UMTSQoSInformation.h"

#ifdef __cplusplus
extern "C" {
#endif

/* UMTSQoSRequested */
typedef UMTSQoSInformation_t	 UMTSQoSRequested_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_UMTSQoSRequested;
asn_struct_free_f UMTSQoSRequested_free;
asn_struct_print_f UMTSQoSRequested_print;
asn_constr_check_f UMTSQoSRequested_constraint;
ber_type_decoder_f UMTSQoSRequested_decode_ber;
der_type_encoder_f UMTSQoSRequested_encode_der;
xer_type_decoder_f UMTSQoSRequested_decode_xer;
xer_type_encoder_f UMTSQoSRequested_encode_xer;

#ifdef __cplusplus
}
#endif

#endif	/* _UMTSQoSRequested_H_ */
#include <asn_internal.h>
