//
//  NuPointer.h
//  Nu
//
//  Created by Tim Burks on 4/24/16.
//
//

#import <Foundation/Foundation.h>
#pragma mark -
#pragma mark Wrapping access to items and objects in memory

/*!
 @class NuPointer
 @abstract The Nu pointer wrapper.
 @discussion The NuPointer class provides a wrapper for pointers to arbitrary locations in memory.
 */
@interface NuPointer : NSObject

/*! Get the value of the pointer. Don't call this from Nu. */
- (void *) pointer;
/*! Set the pointer.  Used by the bridge to create NuReference objects from pointers.  Don't call this from Nu. */
- (void) setPointer:(void *) pointer;
/*! Set the type of a pointer. This should be an Objective-C type encoding that begins with a "^". */
- (void) setTypeString:(NSString *) typeString;
/*! Get an Objective-C type string describing the pointer target. */
- (NSString *) typeString;
/*! Assume the pointer is a pointer to an Objective-C object. Get the object. You had better be right, or this will crash. */
- (id) object;
/*! Get the value of the pointed-to object, using the typeString to determine the correct type */
- (id) value;
/*! Helper function, used internally to reserve space for data of a specified type. */
- (void) allocateSpaceForTypeString:(NSString *) s;
@end

