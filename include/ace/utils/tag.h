#ifndef GUARD_ACE_UTILS_TAG_H
#define GUARD_ACE_UTILS_TAG_H

/**
 * Util for handling AmigaOS tag list pattern.
 */

#include <stdarg.h>
#include <ace/types.h>

#ifdef AMIGA
#include <utility/tagitem.h>
typedef Tag tTag;
#else
typedef ULONG tTag;
#define TAG_DONE   0L
#define TAG_END    0L
#define TAG_IGNORE 1L
#define TAG_MORE   2L
#define TAG_SKIP   3L
#endif // AMIGA

/**
 *  Finds and returns value of specified tag name from tag list.
 *  Tag list may be supplied as list or va_list.
 *  TODO: 1st arg doesn't work yet
 *  @param pTagListPtr  Pointer to tag list.
 *  @param vaSrcList    va_list containing alternating tags and values.
 *  @param ulTagToFind  Tag name, of which value should be returned.
 *  @param ulOnNotFound Value to be returned if tag was not found on list.
 *  @return Zero if tag was not found, otherwise tag value.
 */
ULONG tagGet(
	IN void *pTagListPtr,
	IN va_list vaSrcList,
	IN tTag ulTagToFind,
	IN ULONG ulOnNotFound
);

#endif // GUARD_ACE_UTILS_TAG_H
