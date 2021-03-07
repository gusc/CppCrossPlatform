//
// Created by Gusts Kaksis on 3/6/21.
//

#import <Foundation/Foundation.h>
#import "../MyCrossPlatformClass.hpp"

@interface MyCrossPlatformDelegate : NSObject

-(instancetype)initWithCppObject:(MyCrossPlatformClass*)cppObject;
-(void)platformNativeMethod;
-(void)cppMethod;

@end
