/*
	NSBrowserCell.h
	Application Kit
	Copyright (c) 1994-2011, Apple Inc.
	All rights reserved.
*/

#import <AppKit/NSCell.h>

@class NSImage;

extern class NSBrowserCell extends NSCell

+ (NSImage *)branchImage;
+ (NSImage *)highlightedBranchImage;

- (NSColor *)highlightColorInView:(NSView *)controlView;

- (BOOL)isLeaf;
- (void)setLeaf:(BOOL)flag;
- (BOOL)isLoaded;
- (void)setLoaded:(BOOL)flag;
- (void)reset;
- (void)set;
- (void)setImage:(NSImage *)image;
- (NSImage *)image;
- (void)setAlternateImage:(NSImage *)newAltImage;
- (NSImage *)alternateImage;

}
