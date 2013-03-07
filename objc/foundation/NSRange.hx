package objc.foundation;

extern class NSRange {
	
	public var location :Int;
	public var length :Int;
	public function new (loc:Int, len:Int) :Void;
}

/*
typedef struct _NSRange {
    NSUInteger location;
    NSUInteger length;
} NSRange;

typedef NSRange *NSRangePointer;

NS_INLINE NSRange NSMakeRange(NSUInteger loc, NSUInteger len) {
    NSRange r;
    r.location = loc;
    r.length = len;
    return r;
}

NS_INLINE NSUInteger NSMaxRange(NSRange range) {
    return (range.location + range.length);
}

NS_INLINE Bool NSLocationInRange(NSUInteger loc, NSRange range) {
    return (loc - range.location < range.length);
}

NS_INLINE Bool NSEqualRanges(NSRange range1, NSRange range2) {
    return (range1.location == range2.location && range1.length == range2.length);
}

FOUNDATION_EXPORT NSRange NSUnionRange(NSRange range1, NSRange range2);
FOUNDATION_EXPORT NSRange NSIntersectionRange(NSRange range1, NSRange range2);
FOUNDATION_EXPORT NSString *NSStringFromRange(NSRange range);
FOUNDATION_EXPORT NSRange NSRangeFromString(NSString *aString);

extern class NSValue (NSValueRangeExtensions)

+ (NSValue *)valueWithRange:(NSRange)range;
- (NSRange)rangeValue;

}

*/