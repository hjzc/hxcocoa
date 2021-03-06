//
//  UIBezierPath.h
package ios.ui;

extends enum UIRectCorner {
    UIRectCornerTopLeft;
    UIRectCornerTopRight;
    UIRectCornerBottomLeft;
    UIRectCornerBottomRight;
    UIRectCornerAllCorners;
}

extern class UIBezierPath extends NSObject {

+ (UIBezierPath *)bezierPath;
+ (UIBezierPath *)bezierPathWithRect:(CGRect)rect;
+ (UIBezierPath *)bezierPathWithOvalInRect:(CGRect)rect;
+ (UIBezierPath *)bezierPathWithRoundedRect:(CGRect)rect cornerRadius:(Float)cornerRadius; // rounds all corners with the same horizontal and vertical radius
+ (UIBezierPath *)bezierPathWithRoundedRect:(CGRect)rect byRoundingCorners:(UIRectCorner)corners cornerRadii:(CGSize)cornerRadii;
+ (UIBezierPath *)bezierPathWithArcCenter:(CGPoint)center radius:(Float)radius startAngle:(Float)startAngle endAngle:(Float)endAngle clockwise:(BOOL)clockwise;
+ (UIBezierPath *)bezierPathWithCGPath:(CGPathRef)CGPath;

// Returns an immutable CGPathRef which is only valid until the UIBezierPath is further mutated.
// Setting the path will create an immutable copy of the provided CGPathRef, so any further mutations on a provided CGMutablePathRef will be ignored.
	public var  CGPathRef CGPath;

// Path construction

	public function moveToPoint:(CGPoint)point;
	public function addLineToPoint:(CGPoint)point;
	public function addCurveToPoint:(CGPoint)endPoint controlPoint1:(CGPoint)controlPoint1 controlPoint2:(CGPoint)controlPoint2;
	public function addQuadCurveToPoint:(CGPoint)endPoint controlPoint:(CGPoint)controlPoint;
	public function addArcWithCenter:(CGPoint)center radius:(Float)radius startAngle:(Float)startAngle endAngle:(Float)endAngle clockwise:(BOOL)clockwise NS_AVAILABLE_IOS(4_0);
	public function closePath;

	public function removeAllPoints;

// Appending paths

	public function appendPath:(UIBezierPath *)bezierPath;

// Modified paths

- (UIBezierPath *)bezierPathByReversingPath NS_AVAILABLE_IOS(6_0);

// Transforming paths

	public function applyTransform:(CGAffineTransform)transform;

// Path info

	public var (readonly,getter=isEmpty) BOOL empty;
	public var (default, null) CGRect bounds;
	public var (default, null) CGPoint currentPoint;
- (BOOL)containsPoint:(CGPoint)point;

// Drawing properties

	public var  Float lineWidth;
	public var  CGLineCap lineCapStyle;
	public var  CGLineJoin lineJoinStyle;
	public var  Float miterLimit; // Used when lineJoinStyle is kCGLineJoinMiter
	public var  Float flatness;
	public var  BOOL usesEvenOddFillRule; // Default is NO. When YES, the even-odd fill rule is used for drawing, clipping, and hit testing.

	public function setLineDash:(const Float *)pattern count:(Int)count phase:(Float)phase;
	public function getLineDash:(Float *)pattern count:(Int *)count phase:(Float *)phase;

// Path operations on the current graphics context

	public function fill;
	public function stroke;

// These methods do not affect the blend mode or alpha of the current graphics context
	public function fillWithBlendMode:(CGBlendMode)blendMode alpha:(Float)alpha;
	public function strokeWithBlendMode:(CGBlendMode)blendMode alpha:(Float)alpha;

	public function addClip;

}
