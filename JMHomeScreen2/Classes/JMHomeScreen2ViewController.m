//
//  JMHomeScreen2ViewController.m
//  JMHomeScreen2
//
//  Created by FOLY on 1/22/16.
//  Copyright © 2016 FOLY. All rights reserved.
//

#import "JMHomeScreen2ViewController.h"

#import "JMSlideShow2ViewController.h"
#import "JMButtons2ViewController.h"

@implementation JMHomeScreen2ViewController


- (void)generateAndConfigureSubViewControllers{
    
    JMSlideShow2ViewController *slideShowVC = [self.storyboard instantiateViewControllerWithIdentifier:@"JMSlideShow2ViewController"];
    [self pushSubViewController:slideShowVC];
    
    JMButtons2ViewController *buttonsVC = [self.storyboard instantiateViewControllerWithIdentifier:@"JMButtons2ViewController"];
//    buttonsVC.deficit = 64;
    [self pushSubViewController:buttonsVC];
    
    JMButtons2ViewController *buttonsVC2 = [self.storyboard instantiateViewControllerWithIdentifier:@"JMButtons2ViewController"];
    buttonsVC2.numberOfColumnsInLine = 2;
//    buttonsVC2.deficit = 64;
    [self pushSubViewController:buttonsVC2];
    
    JMButtons2ViewController *buttonsVC3 = [self.storyboard instantiateViewControllerWithIdentifier:@"JMButtons2ViewController"];
    buttonsVC3.numberOfColumnsInLine = 3;
//    buttonsVC3.deficit = 64;
    [self pushSubViewController:buttonsVC3];
    
}

@end
