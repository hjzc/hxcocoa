package ios.ui;

import objc.foundation.NSObject;
import objc.foundation.NSData;
import objc.graphics.CGGeometry;
import objc.graphics.CGImage;

@:framework("UIKit")
extern enum UIImageOrientation {
    UIImageOrientationUp;            // default orientation
    UIImageOrientationDown;          // 180 deg rotation
    UIImageOrientationLeft;          // 90 deg CCW
    UIImageOrientationRight;         // 90 deg CW
    UIImageOrientationUpMirrored;    // as above but image mirrored along other axis. horizontal flip
    UIImageOrientationDownMirrored;  // horizontal flip
    UIImageOrientationLeftMirrored;  // vertical flip
    UIImageOrientationRightMirrored; // vertical flip
}

@:framework("UIKit")
extern enum UIImageResizingMode {
    UIImageResizingModeTile;
    UIImageResizingModeStretch;
}


@:framework("UIKit")
extern class UIImage extends NSObject {
	
	public static function imageNamed (name:String) :UIImage;// load from main bundle
	public static function imageWithContentsOfFile (name:String) :UIImage;// load from main bundle
	public static function imageWithData (name:NSData) :UIImage;// load from main bundle
	public static function imageWithCGImage (cgImage:CGImageRef) :UIImage;// load from main bundle
	
	public var size (default, null) :CGSize; // reflects orientation setting. In iOS 4.0 and later, this is measured in points. In 3.x and earlier, measured in pixels
	
	public function initWithData (data:NSData) :UIImage;
}

/*  

+ (UIImage *)imageWithData:(NSData *)data scale:(Float)scale NS_AVAILABLE_IOS(6_0);
+ (UIImage *)
+ (UIImage *)imageWithCGImage:(CGImageRef)cgImage scale:(Float)scale orientation:(UIImageOrientation)orientation NS_AVAILABLE_IOS(4_0);
+ (UIImage *)imageWithCIImage:(CIImage *)ciImage NS_AVAILABLE_IOS(5_0);
+ (UIImage *)imageWithCIImage:(CIImage *)ciImage scale:(Float)scale orientation:(UIImageOrientation)orientation NS_AVAILABLE_IOS(6_0);

- (id)initWithContentsOfFile:(String *)path;
- (id)initWithData:(NSData *)data;.............
- (id)initWithData:(NSData *)data scale:(Float)scale NS_AVAILABLE_IOS(6_0);
- (id)initWithCGImage:(CGImageRef)cgImage;
- (id)initWithCGImage:(CGImageRef)cgImage scale:(Float)scale orientation:(UIImageOrientation)orientation NS_AVAILABLE_IOS(4_0);
- (id)initWithCIImage:(CIImage *)ciImage NS_AVAILABLE_IOS(5_0);
- (id)initWithCIImage:(CIImage *)ciImage scale:(Float)scale orientation:(UIImageOrientation)orientation NS_AVAILABLE_IOS(6_0);

	
	public var (default, null) CGImageRef         CGImage;          // returns underlying CGImageRef or nil if CIImage based
	public var (default, null) CIImage           *CIImage NS_AVAILABLE_IOS(5_0); // returns underlying CIImage or nil if CGImageRef based
	public var (default, null) UIImageOrientation imageOrientation; // this will affect how the image is composited
	public var (default, null) Float            scale NS_AVAILABLE_IOS(4_0);

// animated images. When set as UIImageView.image, animation will play in an infinite loop until removed. Drawing will render the first image

+ (UIImage *)animatedImageNamed:(String *)name duration:(NSTimeInterval)duration NS_AVAILABLE_IOS(5_0);  // read sequence of files with suffix starting at 0 or 1
+ (UIImage *)animatedResizableImageNamed:(String *)name capInsets:(UIEdgeInsets)capInsets duration:(NSTimeInterval)duration NS_AVAILABLE_IOS(5_0); // sequence of files
+ (UIImage *)animatedResizableImageNamed:(String *)name capInsets:(UIEdgeInsets)capInsets resizingMode:(UIImageResizingMode)resizingMode duration:(NSTimeInterval)duration NS_AVAILABLE_IOS(6_0);
+ (UIImage *)animatedImageWithImages:(NSArray *)images duration:(NSTimeInterval)duration NS_AVAILABLE_IOS(5_0);

	public var (default, null) NSArray       *images   NS_AVAILABLE_IOS(5_0); // default is nil for non-animated images
	public var (default, null) NSTimeInterval duration NS_AVAILABLE_IOS(5_0); // total duration for all frames. default is 0 for non-animated images

// the these draw the image 'right side up' in the usual coordinate system with 'point' being the top-left.

	public function drawAtPoint:(CGPoint)point;                                                        // mode = kCGBlendModeNormal, alpha = 1.0
	public function drawAtPoint:(CGPoint)point blendMode:(CGBlendMode)blendMode alpha:(Float)alpha;
	public function drawInRect:(CGRect)rect;                                                           // mode = kCGBlendModeNormal, alpha = 1.0
	public function drawInRect:(CGRect)rect blendMode:(CGBlendMode)blendMode alpha:(Float)alpha;

	public function drawAsPatternInRect:(CGRect)rect; // draws the image as a CGPattern

- (UIImage *)resizableImageWithCapInsets:(UIEdgeInsets)capInsets NS_AVAILABLE_IOS(5_0); // create a resizable version of this image. the interior is tiled when drawn.
- (UIImage *)resizableImageWithCapInsets:(UIEdgeInsets)capInsets resizingMode:(UIImageResizingMode)resizingMode NS_AVAILABLE_IOS(6_0); // the interior is resized according to the resizingMode

	public var (default, null) UIEdgeInsets capInsets               NS_AVAILABLE_IOS(5_0);   // default is UIEdgeInsetsZero for non resizable images
	public var (default, null) UIImageResizingMode resizingMode NS_AVAILABLE_IOS(6_0); // default is UIImageResizingModeTile

// Support for constraint-based layout (auto layout)
// The alignmentRectInsets of a UIImage are used by UIImageView and other UIView and UIControl
//  subclasses that take custom images to determine the view's alignment rect insets for
//  constraint-based layout.
// The default alignmentRectInsets are UIEdgeInsetsZero.
- (UIImage *)imageWithAlignmentRectInsets:(UIEdgeInsets)alignmentInsets NS_AVAILABLE_IOS(6_0);
	public var (default, null) UIEdgeInsets alignmentRectInsets NS_AVAILABLE_IOS(6_0);

}



extern class CIImage(UIKitAdditions)

- (id)initWithImage:(UIImage *)image NS_AVAILABLE_IOS(5_0);
- (id)initWithImage:(UIImage *)image options:(NSDictionary *)options NS_AVAILABLE_IOS(5_0);

}

UIKIT_EXTERN NSData *UIImagePNGRepresentation(UIImage *image);                               // return image as PNG. May return nil if image has no CGImageRef or invalid bitmap format
UIKIT_EXTERN NSData *UIImageJPEGRepresentation(UIImage *image, Float compressionQuality); */
