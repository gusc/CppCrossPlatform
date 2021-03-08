//
// Created by Gusts Kaksis on 3/6/21.
//

#import <UIKit/UIKit.h>
#import "AppDelegate.hpp"

int main(int argc, char * argv[]) {
    NSString * appDelegateClassName;
    @autoreleasepool {
        // Setup code that might create autoreleased objects goes here.
        appDelegateClassName = NSStringFromClass([AppDelegate class]);
    }
    return UIApplicationMain(argc, argv, nil, appDelegateClassName);
}
