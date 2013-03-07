/*
	NSNibConnector.h
	Application Kit
	Copyright (c) 1994-2011, Apple Inc.
	All rights reserved.
*/

#import <Foundation/NSObject.h>

extern class NSNibConnector extends NSObject, implements NSObject>
{
    @private
    id _source;		/* The source of the connection. */
    id _destination;	/* The destination of the connection. */
    NSString *_label;	/* The label of the connection. */
}
- (id)source;
- (void)setSource:(id)source;
- (id)destination;
- (void)setDestination:(id)destination;
- (NSString *)label;
- (void)setLabel:(NSString *)label;
- (void)replaceObject:(id)oldObject withObject:(id)newObject;
- (void)establishConnection;
}
