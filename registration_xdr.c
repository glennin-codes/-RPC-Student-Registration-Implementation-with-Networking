/*
 * Please do not edit this file.
 * It was generated using rpcgen.
 */

#include "registration.h"

bool_t
xdr_Student (XDR *xdrs, Student *objp)
{
	register int32_t *buf;

	 if (!xdr_int (xdrs, &objp->regNum))
		 return FALSE;
	 if (!xdr_string (xdrs, &objp->name, ~0))
		 return FALSE;
	return TRUE;
}