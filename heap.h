/*
 * defines for the system specific memory routines
 *
 * Copyright 1995 by Gray Watson
 *
 * This file is part of the dmalloc package.
 *
 * Permission to use, copy, modify, and distribute this software for any
 * NON-COMMERCIAL purpose and without fee is hereby granted, provided
 * that the above copyright notice and this permission notice appear
 * in all copies, and that the name of Gray Watson not be used in
 * advertising or publicity pertaining to distribution of the document
 * or software without specific, written prior permission.
 *
 * Please see the PERMISSIONS file or contact the author for information
 * about commercial licenses.
 *
 * Gray Watson makes no representations about the suitability of the
 * software described herein for any purpose.  It is provided "as is"
 * without express or implied warranty.
 *
 * The author may be contacted at gray.watson@letters.com
 *
 * $Id: heap.h,v 1.27 1995/08/30 18:04:57 gray Exp $
 */

#ifndef __HEAP_H__
#define __HEAP_H__

#include "dmalloc_loc.h"			/* for LOCAL and BLOCK_SIZE */

/*
 * error code returned by heap allocation routine
 */
#define HEAP_ALLOC_ERROR	0L

/*
 * probably machine specific defines used for certain calculations
 */
#if HEAP_GROWS_UP

/* test whether pointer P is in the heap space */
#define IS_IN_HEAP(p)		\
  ((char *)(p) >= (char *)_heap_base && (char *)(p) < (char *)_heap_last)

/* turn pointer P into a block index */
#define WHICH_BLOCK(p)		\
  (((char *)(p) - (char *)_heap_base) / BLOCK_SIZE)

/* get a pointer to the memory block number C */
#define BLOCK_POINTER(c)	((char *)_heap_base + (c) * BLOCK_SIZE)

/* test whether pointer P is on a block boundary */
#define ON_BLOCK(p)		\
  (((char *)(p) - (char *)_heap_base) % BLOCK_SIZE == 0)

/* calculate the size of heap */
#define HEAP_SIZE		((char *)_heap_last - (char *)_heap_base)

#else /* ! HEAP_GROWS_UP */

/* test whether pointer P is in the heap space */
#define IS_IN_HEAP(p)		\
  ((char *)(p) <= (char *)_heap_base && (char *)(p) > (char *)_heap_last)

/* turn pointer P into a block index */
#define WHICH_BLOCK(p)		\
  (((char *)(_heap_base) - (char *)p) / BLOCK_SIZE)

/* get a pointer to the memory block number C */
#define BLOCK_POINTER(c)	((char *)_heap_base - (c) * BLOCK_SIZE)

/* test whether pointer P is on a block boundary */
#define ON_BLOCK(p)		\
  (((char *)(_heap_base) - (char *)p) % BLOCK_SIZE == 0)

/* calculate the size of heap */
#define HEAP_SIZE		((char *)_heap_base - (char *)_heap_last)

#endif /* ! HEAP_GROWS_UP */

/*<<<<<<<<<<  The below prototypes are auto-generated by fillproto */

IMPORT	void		*_heap_base;  /* base of our heap */

IMPORT	void		*_heap_last;  /* end of our heap */

/*
 * function to get SIZE memory bytes from the end of the heap
 */
IMPORT	void	*_heap_alloc(const unsigned int size);

/*
 * return a pointer to the current end of the heap
 */
IMPORT	void	*_heap_end(void);

/*
 * initialize heap pointers.  returns [NO]ERROR
 */
IMPORT	int	_heap_startup(void);

/*
 * align (by extending) _heap_base to block_size byte boundary
 */
IMPORT	void	*_heap_align_base(void);

/*<<<<<<<<<<   This is end of the auto-generated output from fillproto. */

#endif /* ! __HEAP_H__ */
