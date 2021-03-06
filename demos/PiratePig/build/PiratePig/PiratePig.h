//
//  PiratePig
//  PiratePig
//
//  Source generated by Haxe Objective-C target
//


#import <UIKit/UIKit.h>
#import <Foundation/Foundation.h>
#import <CoreGraphics/CoreGraphics.h>

#import "PiratePigGame.h"
#import "haxe/Log.h"

@interface PiratePig : UIResponder <UIApplicationDelegate>


@property (nonatomic, strong) UIWindow *window;
@property (nonatomic, strong) UIViewController *viewController;
@property (nonatomic, strong) UIView *view;
@property (nonatomic, strong) UIImageView *background;
@property (nonatomic, strong) UIImageView *footer;
@property (nonatomic, strong) PiratePigGame *game;
- (BOOL) application:(UIApplication*)application didFinishLaunchingWithOptions:(NSDictionary*)didFinishLaunchingWithOptions;
- (void) initialize;
- (void) construct;
- (void) applicationDidBecomeActive:(UIApplication*)application;
- (void) applicationWillResignActive:(UIApplication*)application;

@end

