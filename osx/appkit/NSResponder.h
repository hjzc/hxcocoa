/*
        NSResponder.h
        Application Kit
        Copyright (c) 1994-2011, Apple Inc.
        All rights reserved.
*/

#import <Foundation/NSObject.h>
#import <AppKit/NSEvent.h>

@class NSArray, NSError, NSEvent, NSMenu, NSUndoManager, NSWindow;

extern class NSResponder extends NSObject, implements NSObject>
{
    /*All instance variables are private*/
    id _nextResponder;
}

- (NSResponder *)nextResponder;
- (void)setNextResponder:(NSResponder *)aResponder;
- (BOOL)tryToPerform:(SEL)anAction with:(id)anObject;
- (BOOL)performKeyEquivalent:(NSEvent *)theEvent;
- (id)validRequestorForSendType:(NSString *)sendType returnType:(NSString *)returnType;
- (void)mouseDown:(NSEvent *)theEvent;
- (void)rightMouseDown:(NSEvent *)theEvent;
- (void)otherMouseDown:(NSEvent *)theEvent;
- (void)mouseUp:(NSEvent *)theEvent;
- (void)rightMouseUp:(NSEvent *)theEvent;
- (void)otherMouseUp:(NSEvent *)theEvent;
- (void)mouseMoved:(NSEvent *)theEvent;
- (void)mouseDragged:(NSEvent *)theEvent;
- (void)scrollWheel:(NSEvent *)theEvent;
- (void)rightMouseDragged:(NSEvent *)theEvent;
- (void)otherMouseDragged:(NSEvent *)theEvent;
- (void)mouseEntered:(NSEvent *)theEvent;
- (void)mouseExited:(NSEvent *)theEvent;
- (void)keyDown:(NSEvent *)theEvent;
- (void)keyUp:(NSEvent *)theEvent;
- (void)flagsChanged:(NSEvent *)theEvent;
- (void)tabletPoint:(NSEvent *)theEvent;
- (void)tabletProximity:(NSEvent *)theEvent;
- (void)cursorUpdate:(NSEvent *)event NS_AVAILABLE_MAC(10_5);
/* The following *WithEvent methods are available on 10.5.2 or later, and will be sent only on hardware capable of generating the corresponding NSEvent types 
*/
- (void)magnifyWithEvent:(NSEvent *)event NS_AVAILABLE_MAC(10_5);
- (void)rotateWithEvent:(NSEvent *)event NS_AVAILABLE_MAC(10_5);
- (void)swipeWithEvent:(NSEvent *)event NS_AVAILABLE_MAC(10_5);
- (void)beginGestureWithEvent:(NSEvent *)event NS_AVAILABLE_MAC(10_5);
- (void)endGestureWithEvent:(NSEvent *)event NS_AVAILABLE_MAC(10_5);


/* A new set of touches has been recognized. To get the set of touches that began for this view (or descendants of this view): [event touchesMatchingPhase:NSTouchPhaseBegan inView:self]; Note: this is not always the point of contact with the touch device. A touch that transitions from resting to active may be part of a Began set.
*/
- (void)touchesBeganWithEvent:(NSEvent *)event NS_AVAILABLE_MAC(10_6);

/* One or more touches has moved. To get the set of touches that moved for this view (or descendants of this view): [event touchesMatchingPhase:NSTouchPhaseMoved inView:self];
*/ 
- (void)touchesMovedWithEvent:(NSEvent *)event NS_AVAILABLE_MAC(10_6);

/* A set of touches have been removed. To get the set of touches that ended for this view (or descendants of this view): [event touchesMatchingPhase:NSTouchPhaseEnded inView:self]; Note: this is not always the point of removal with the touch device. A touch that transitions from active to resting may be part of an Ended set.
*/
- (void)touchesEndedWithEvent:(NSEvent *)event NS_AVAILABLE_MAC(10_6);

/* The System has cancelled the tracking of touches for any reason.
*/
- (void)touchesCancelledWithEvent:(NSEvent *)event NS_AVAILABLE_MAC(10_6);

- (void)noResponderFor:(SEL)eventSelector;
- (BOOL)acceptsFirstResponder;
- (BOOL)becomeFirstResponder;
- (BOOL)resignFirstResponder;

- (void)interpretKeyEvents:(NSArray *)eventArray;
- (void)flushBufferedKeyEvents;

- (void)setMenu:(NSMenu *)menu;
- (NSMenu *)menu;

- (void)showContextHelp:(id)sender;

- (void)helpRequested:(NSEvent *)eventPtr;

- (BOOL)shouldBeTreatedAsInkEvent:(NSEvent *)theEvent;

/* Some views process gesture scroll events to perform elastic scrolling. In some cases, you may want to track gesture scroll events like a swipe. (see -trackSwipeEventWithOptions:dampenAmountThresholdMin:max:usingHandler: in NSEvent.h) Implement this method and return YES in your swipe controller and views that perform elastic scrolling will forward gesture scroll events up the responder chain on the following condition: the content to be scrolled is already at the edge of the scrolled direction at the beginning of the scroll gesture. Otherwise, the view will perform elastic scrolling. Default implementation returns NO.
*/
- (BOOL)wantsScrollEventsForSwipeTrackingOnAxis:(NSEventGestureAxis)axis NS_AVAILABLE_MAC(10_7);

/* Some views process gesture scroll events to perform elastic scrolling. In some cases, the scroll events should be forwarded up the responder chain for further processing (for example an enclosing scroll view). Implement this method returning yes and views that perform elastic scrolling will forward gesture scroll events up the responder chain on the following condition: the content to be scrolled is already at the edge of the scrolled direction at the beginning of the scroll gesture. Otherwise, the view will perform elastic scrolling. Note: If you intend to call -trackSwipeEventWithOptions:dampenAmountThresholdMin:max:usingHandler: implement -wantsToTrackScrollEventsAsSwipeForAxis, as defined above instead. Default implementation returns NO.
*/
- (BOOL)wantsForwardedScrollEventsForAxis:(NSEventGestureAxis)axis NS_AVAILABLE_MAC(10_7);

/* This method is used in the process of finding a target for an action method. If this NSResponder instance does not itself respondsToSelector:action, then supplementalTargetForAction:sender: is called. This method should return an object which responds to the action; if this responder does not have a supplemental object that does that, the implementation of this method should call super's supplementalTargetForAction:sender:. NSResponder's implementation returns nil.
*/
- (id)supplementalTargetForAction:(SEL)action sender:(id)sender NS_AVAILABLE_MAC(10_7);
}

extern class NSResponder(NSKeyboardUI)
- (BOOL)performMnemonic:(NSString *)theString;
}

extern class NSResponder (NSStandardKeyBindingMethods)

// This category contains a large number of methods intended for use as key binding commands.  NSResponder does not implement any of them.  NSTextView implements a certain subset of them (see the NSTextView.h header).  Your responder subclasses can implement any that make sense.  You can make up your own as well, but you should use these if the concepts map.  If your view is key and uses key binding and the user types a key sequence which is bound to a command which is not implemented in your class, it is OK, nothing will happen by default.

/************************* Key binding entry-points *************************/

- (void)insertText:(id)insertString;
    // When key events have been passed off to the key binding mechanism through interpretKeyEvents:, they end up back in the view through either this method or the below doCommand... methods.  insertText: is used to pass through text that was not a command.

- (void)doCommandBySelector:(SEL)aSelector;
    // Performs the given selector if possible.

/************************* Standard bindable commands *************************/

    /* Selection movement and scrolling */

- (void)moveForward:(id)sender;
- (void)moveRight:(id)sender;
- (void)moveBackward:(id)sender;
- (void)moveLeft:(id)sender;
- (void)moveUp:(id)sender;
- (void)moveDown:(id)sender;
- (void)moveWordForward:(id)sender;
- (void)moveWordBackward:(id)sender;
- (void)moveToBeginningOfLine:(id)sender;
- (void)moveToEndOfLine:(id)sender;
- (void)moveToBeginningOfParagraph:(id)sender;
- (void)moveToEndOfParagraph:(id)sender;
- (void)moveToEndOfDocument:(id)sender;
- (void)moveToBeginningOfDocument:(id)sender;
- (void)pageDown:(id)sender;
- (void)pageUp:(id)sender;
- (void)centerSelectionInVisibleArea:(id)sender;

- (void)moveBackwardAndModifySelection:(id)sender;
- (void)moveForwardAndModifySelection:(id)sender;
- (void)moveWordForwardAndModifySelection:(id)sender;
- (void)moveWordBackwardAndModifySelection:(id)sender;
- (void)moveUpAndModifySelection:(id)sender;
- (void)moveDownAndModifySelection:(id)sender;

- (void)moveToBeginningOfLineAndModifySelection:(id)sender;
- (void)moveToEndOfLineAndModifySelection:(id)sender;
- (void)moveToBeginningOfParagraphAndModifySelection:(id)sender;
- (void)moveToEndOfParagraphAndModifySelection:(id)sender;
- (void)moveToEndOfDocumentAndModifySelection:(id)sender;
- (void)moveToBeginningOfDocumentAndModifySelection:(id)sender;
- (void)pageDownAndModifySelection:(id)sender;
- (void)pageUpAndModifySelection:(id)sender;
- (void)moveParagraphForwardAndModifySelection:(id)sender;
- (void)moveParagraphBackwardAndModifySelection:(id)sender;

- (void)moveWordRight:(id)sender;
- (void)moveWordLeft:(id)sender;
- (void)moveRightAndModifySelection:(id)sender;
- (void)moveLeftAndModifySelection:(id)sender;
- (void)moveWordRightAndModifySelection:(id)sender;
- (void)moveWordLeftAndModifySelection:(id)sender;

- (void)moveToLeftEndOfLine:(id)sender NS_AVAILABLE_MAC(10_6);
- (void)moveToRightEndOfLine:(id)sender NS_AVAILABLE_MAC(10_6);
- (void)moveToLeftEndOfLineAndModifySelection:(id)sender NS_AVAILABLE_MAC(10_6);
- (void)moveToRightEndOfLineAndModifySelection:(id)sender NS_AVAILABLE_MAC(10_6);

- (void)scrollPageUp:(id)sender;
- (void)scrollPageDown:(id)sender;
- (void)scrollLineUp:(id)sender;
- (void)scrollLineDown:(id)sender;

- (void)scrollToBeginningOfDocument:(id)sender;
- (void)scrollToEndOfDocument:(id)sender;

    /* Graphical Element transposition */

- (void)transpose:(id)sender;
- (void)transposeWords:(id)sender;

    /* Selections */

- (void)selectAll:(id)sender;
- (void)selectParagraph:(id)sender;
- (void)selectLine:(id)sender;
- (void)selectWord:(id)sender;

    /* Insertions and Indentations */

- (void)indent:(id)sender;
- (void)insertTab:(id)sender;
- (void)insertBacktab:(id)sender;
- (void)insertNewline:(id)sender;
- (void)insertParagraphSeparator:(id)sender;
- (void)insertNewlineIgnoringFieldEditor:(id)sender;
- (void)insertTabIgnoringFieldEditor:(id)sender;
- (void)insertLineBreak:(id)sender;
- (void)insertContainerBreak:(id)sender;
- (void)insertSingleQuoteIgnoringSubstitution:(id)sender NS_AVAILABLE_MAC(10_5);
- (void)insertDoubleQuoteIgnoringSubstitution:(id)sender NS_AVAILABLE_MAC(10_5);

    /* Case changes */

- (void)changeCaseOfLetter:(id)sender;
- (void)uppercaseWord:(id)sender;
- (void)lowercaseWord:(id)sender;
- (void)capitalizeWord:(id)sender;

    /* Deletions */

- (void)deleteForward:(id)sender;
- (void)deleteBackward:(id)sender;
- (void)deleteBackwardByDecomposingPreviousCharacter:(id)sender;
- (void)deleteWordForward:(id)sender;
- (void)deleteWordBackward:(id)sender;
- (void)deleteToBeginningOfLine:(id)sender;
- (void)deleteToEndOfLine:(id)sender;
- (void)deleteToBeginningOfParagraph:(id)sender;
- (void)deleteToEndOfParagraph:(id)sender;

- (void)yank:(id)sender;

    /* Completion */

- (void)complete:(id)sender;

    /* Mark/Point manipulation */

- (void)setMark:(id)sender;
- (void)deleteToMark:(id)sender;
- (void)selectToMark:(id)sender;
- (void)swapWithMark:(id)sender;

    /* Cancellation */

- (void)cancelOperation:(id)sender;

    /* Writing Direction */

- (void)makeBaseWritingDirectionNatural:(id)sender NS_AVAILABLE_MAC(10_6);
- (void)makeBaseWritingDirectionLeftToRight:(id)sender NS_AVAILABLE_MAC(10_6);
- (void)makeBaseWritingDirectionRightToLeft:(id)sender NS_AVAILABLE_MAC(10_6);

- (void)makeTextWritingDirectionNatural:(id)sender NS_AVAILABLE_MAC(10_6);
- (void)makeTextWritingDirectionLeftToRight:(id)sender NS_AVAILABLE_MAC(10_6);
- (void)makeTextWritingDirectionRightToLeft:(id)sender NS_AVAILABLE_MAC(10_6);

}

extern class NSResponder(NSUndoSupport)
- (NSUndoManager *)undoManager;
}

extern class NSResponder (NSControlEditingSupport)

/* This is a responder chain method to allow controls to determine when they should become first responder or not. Some controls, such as NSTextField, should only become first responder when the enclosing NSTableView/NSBrowser indicates that the view can begin editing. It is up to the particular control that wants to be validated to call this method in its -mouseDown: (or other time) to determine if it should attempt to become the first responder or not. The default implementation returns YES when there is no -nextResponder, otherwise, it is forwarded up the responder chain. NSTableView/NSBrowser implements this to only allow first responder status if the responder is a view in a selected row. It also delays the first responder assignment if a doubleAction needs to (possibly) be sent. 'event' may be nil if there is no applicable event.
 */
- (BOOL)validateProposedFirstResponder:(NSResponder *)responder forEvent:(NSEvent *)event NS_AVAILABLE_MAC(10_7);

}



extern class NSResponder(NSErrorPresentation)

/* Present an error alert to the user, as a document-modal panel. When the user has dismissed the alert and any recovery possible for the error and chosen by the user has been attempted, send the selected message to the specified delegate. The method selected by didPresentSelector must have the same signature as:

    - (void)didPresentErrorWithRecovery:(BOOL)didRecover contextInfo:(void *)contextInfo;

The default implementation of this method always invokes [self willPresentError:error] to give subclassers an opportunity to customize error presentation. It then forwards the message, passing the customized error, to the next responder or, if there is no next responder, NSApp. NSApplication's override of this method invokes [[NSAlert alertWithError:theErrorToPresent] beginSheetModalForWindow:window modalDelegate:self didEndSelector:selectorForAPrivateMethod contextInfo:privateContextInfo]. When the user has dismissed the alert, the error's recovery attempter is sent an -attemptRecoveryFromError:optionIndex:delegate:didRecoverSelector:contextInfo: message, if the error had recovery options and a recovery delegate.

Errors for which ([[error domain] isEqualToString:NSCocoaErrorDomain] && [error code]==NSUserCancelledError) are a special case,  because they do not actually represent errors and should not be presented as such to the user. NSApplication's override of this method does not present an alert to the user for these kinds of errors. Instead it merely invokes the delegate specifying didRecover==NO.

Between the responder chain in a typical application and various overrides of this method in AppKit classes, objects are given the opportunity to present errors in orders like these:

    For windows owned by documents:
    view -> superviews -> window -> window controller -> document -> document controller -> application

    For windows that have window controllers but aren't associated with documents:
    view -> superviews -> window -> window controller -> application

    For windows that have no window controller at all:
    view -> superviews -> window -> application

You can invoke this method to present error alert sheets. For example, Cocoa's own -[NSDocument saveToURL:ofType:forSaveOperation:delegate:didSaveSelector:contextInfo:] invokes this method when it's just invoked -saveToURL:ofType:forSaveOperation:completionHandler: and that method has signalled an error.

You probably shouldn't override this method, because you have no way of reliably predicting whether this method vs. -presentError will be invoked for any particular error. You should instead override the -willPresentError: method described below.
*/
- (void)presentError:(NSError *)error modalForWindow:(NSWindow *)window delegate:(id)delegate didPresentSelector:(SEL)didPresentSelector contextInfo:(void *)contextInfo;

/* Present an error alert to the user, as an application-modal panel, and return YES if error recovery was done, NO otherwise. This method behaves much like the previous one except it does not return until the user has dismissed the alert and, if the error had recovery options and a recovery delegate, the error's recovery delegate has been sent an -attemptRecoveryFromError:optionIndex: message.

You can invoke this method to present error alert dialog boxes. For example, Cocoa's own [NSDocumentController openDocument:] invokes this method when document opening fails.

You probably shouldn't override this method, because you have no way of reliably predicting whether this method vs. -presentError:modalForWindow:delegate:didPresentSelector:contextInfo: will be invoked for any particular error. You should instead override the -willPresentError: method described below.
*/
- (BOOL)presentError:(NSError *)error;

/* Given that the receiver is about to present an error (perhaps by just forwarding it to the next responder), return the error that should actually be presented. The default implementation of this method merely returns the passed-in error.

You can override this method to customize the presentation of errors by examining the passed-in error and if, for example, its localized description or recovery information is unsuitably generic, returning a more specific one. When you override this method always check the NSError's domain and code to discriminate between errors whose presentation you want to customize and those you don't. For those you don't just return [super willPresentError:error]. Don't make decisions based on the NSError's localized description, recovery suggestion, or recovery options because it's usually not a good idea to try to parse localized text.
*/
- (NSError *)willPresentError:(NSError *)error;

}


extern class NSResponder(NSTextFinderSupport)

- (void)performTextFinderAction:(id)sender NS_AVAILABLE_MAC(10_7);

}
