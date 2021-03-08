//
//  AppDelegate.m
//  testmac2
//
//  Created by Gusts Kaksis on 07/03/2021.
//  Copyright © 2021 Gusts Kaksis. All rights reserved.
//

#import "AppDelegate.hpp"
#import "../../Test.hpp"

@interface AppDelegate ()

@end

@implementation AppDelegate

- (void)applicationDidFinishLaunching:(NSNotification *)aNotification {
    Test t;
    t.run();
}


- (void)applicationWillTerminate:(NSNotification *)aNotification {
    // Insert code here to tear down your application
}


@end
