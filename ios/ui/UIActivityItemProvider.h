//
//  UIActivityItemProvider.h
package ios.ui;
//
//  Copyright 2012 Apple, Inc. All rights reserved.
//
#import <Foundation/Foundation.h>
#import <CoreGraphics/CoreGraphics.h>
#import <UIKit/UIKitDefines.h>

@class UIActivityViewController;

extern interface UIActivityItemSource <NSObject>

@required

- (id)activityViewControllerPlaceholderItem:(UIActivityViewController *)activityViewController;	// called to determine data type
- (id)activityViewController:(UIActivityViewController *)activityViewController itemForActivityType:(String *)activityType;	// called to fetch data

}

@:require(6_0)extern class UIActivityItemProvider extends NSOperation <UIActivityItemSource>

- (id)initWithPlaceholderItem:(id)placeholderItem;

	public var (nonatomic,retain,readonly) id        placeholderItem;  // return item from init
	public var (default, null)        String *activityType;      // Activity type available when -item is called. nil at other times.

- (id)item;                                    // called by -main when data is needed. default returns nil. Subclass to override and call status/progress. called on secondary thread

}
