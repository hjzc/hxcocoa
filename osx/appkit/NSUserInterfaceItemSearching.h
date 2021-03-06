/*
    NSUserInterfaceItemSearching.h
    Application Kit
    Copyright (c) 2008-2011, Apple Inc.
    All rights reserved.
*/

#import <Foundation/NSString.h>
#import <AppKit/NSApplication.h>


@protocol NSUserInterfaceItemSearching <NSObject>
#if MAC_OS_X_VERSION_MAX_ALLOWED >= MAC_OS_X_VERSION_10_6

@required

/*  Search for items matching the provided search string and return them by calling the matched items block, passing an array of items to append to the help menu.  The framework does not care what these items are. They are just used to identify particular search results to other methods in this protocol.  Do not assume that this will be called from the main UI thread.  When searchForItemsWithSearchString gets called again, the client should cancel any previous searches in progress for better performance.  If not Spotlight for Help will ignore the older results.  resultLimit is the maximum number of results that Spotlight for Help will process.  Any results returned beyond this limit will be ignored, but for performance reasons it is better to not exceed it.

    The handleMatchedItems block can be invoked from any thread desired.  If it is called more than once the additional results will be appended after previous items until the maximum is reached.
 */
#if NS_BLOCKS_AVAILABLE
- (void)searchForItemsWithSearchString:(NSString *)searchString resultLimit:(Int)resultLimit matchedItemHandler:(void (^)(NSArray *items))handleMatchedItems;
#endif

/* return an array of strings (localized for display in the menu) that will be combined with separators to form the menu item title
 */
- (NSArray *)localizedTitlesForItem:(id)item;

@optional

/* Called when the user selects a search result in Help menu. For example, the default implementation brings up Help Viewer for a Help item. 
 */
- (void)performActionForItem:(id)item;

/* If this method is implemented, a "Show All Help Topics" item will appear in the menu and this method is called when the user selects it.  The application should show all its results for this search, which does not include results for Menu Items.  The string for "Show All Help Topics" is system defined and localized and cannot be changed by the user.
 */
- (void)showAllHelpTopicsForSearchString:(NSString *)searchString;

#endif
}


extern class NSApplication (NSUserInterfaceItemSearching)

/* Register an an object that conforms to NSUserInterfaceItemSearching with the application.  You can register as many as you like.  If you register the same instance more than once the subsequent registrations are ignored
 */
- (void)registerUserInterfaceItemSearchHandler:(id<NSUserInterfaceItemSearching>)handler NS_AVAILABLE_MAC(10_6);

/* Unregister an object that conforms to NSUserInterfaceItemSearching with the application.  If you unregister the same instance more than once the subsequent registrations are ignored. Also, unregistering an instance that was never registered is a NOP.
 */
- (void)unregisterUserInterfaceItemSearchHandler:(id<NSUserInterfaceItemSearching>)handler NS_AVAILABLE_MAC(10_6);

/* returns YES if searchString matches the supplied range of stringToBeSearched according to Spotlight for Help default matching rules  
 * if found range is non null then the matching range is returned in it 
 */
- (BOOL)searchString:(NSString *)searchString inUserInterfaceItemString:(NSString *)stringToSearch searchRange:(NSRange)searchRange foundRange:(NSRange *)foundRange NS_AVAILABLE_MAC(10_6);

}

