/*
 * Defines for memory protection routines
 *
 * Copyright 2000 by Gray Watson
 *
 * This file is part of the dmalloc package.
 *
 * Permission to use, copy, modify, and distribute this software for
 * any purpose and without fee is hereby granted, provided that the
 * above copyright notice and this permission notice appear in all
 * copies, and that the name of Gray Watson not be used in advertising
 * or publicity pertaining to distribution of the document or software
 * without specific, written prior permission.
 *
 * Gray Watson makes no representations about the suitability of the
 * software described herein for any purpose.  It is provided "as is"
 * without express or implied warranty.
 *
 * The author may be contacted via http://dmalloc.com/
 *
 * $Id: protect.h,v 1.2 2000/05/15 22:30:46 gray Exp $
 */

#ifndef __PROTECT_H__
#define __PROTECT_H__

/*<<<<<<<<<<  The below prototypes are auto-generated by fillproto */

/*
 * void protect_set_read_only
 *
 * DESCRIPTION:
 *
 * Set the protections on a block to be read-only.
 *
 * RETURNS:
 *
 * None.
 *
 * ARGUMENTS:
 *
 * block_pnt -> Pointer to block that we are protecting.
 *
 * block_n -> Number of blocks that we are protecting.
 */
extern
void	protect_set_read_only(void *block_pnt, const int block_n);

/*
 * void protect_set_read_write
 *
 * DESCRIPTION:
 *
 * Set the protections on a block to be read-write.
 *
 * RETURNS:
 *
 * None.
 *
 * ARGUMENTS:
 *
 * block_pnt -> Pointer to block that we are protecting.
 *
 * block_n -> Number of blocks that we are protecting.
 */
extern
void	protect_set_read_write(void *block_pnt, const int block_n);

/*
 * void protect_set_no_access
 *
 * DESCRIPTION:
 *
 * Set the protections on a block to be no-access.
 *
 * RETURNS:
 *
 * None.
 *
 * ARGUMENTS:
 *
 * block_pnt -> Pointer to block that we are protecting.
 *
 * block_n -> Number of blocks that we are protecting.
 */
extern
void	protect_set_no_access(void *block_pnt, const int block_n);

/*<<<<<<<<<<   This is end of the auto-generated output from fillproto. */

#endif /* ! __PROTECT_H__ */