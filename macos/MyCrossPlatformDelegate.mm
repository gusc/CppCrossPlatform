//
// Created by Gusts Kaksis on 3/6/21.
//

#import "MyCrossPlatformDelegate.hpp"

@implementation MyCrossPlatformDelegate
{
    // Hold instance to C++ object
    MyCrossPlatformClass* _cppObject;
}

-(instancetype)initWithCppObject:(MyCrossPlatformClass *)cppObject
{
    self = [super init];
    if (self)
    {
        _cppObject = cppObject;
    }
    return self;
}

-(void)platformNativeMethod
{
    NSLog(@"Objective-C method called");
}

-(void)cppMethod
{
    // Simply call C++ method
    _cppObject->cppMethod();
}

@end
