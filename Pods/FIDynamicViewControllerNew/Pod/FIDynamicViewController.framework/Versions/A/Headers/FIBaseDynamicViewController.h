//
//  FIBaseDynamicViewController.h
//  FIDynamicViewController
//
//  Created by NGUYEN CHI CONG on 8/7/15.
//  Copyright (c) 2015 NGUYEN CHI CONG. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "FIDynamicViewControllerProtocol.h"

@interface FIBaseDynamicViewController : UIViewController<FIDynamicViewControllerProtocol>

/**
  Model for storing data model in view controller
*/
@property (nonatomic, strong) id __nonnull dynamicPresenter;

/**
  Call this method to update model presenter
*/
- (void)updatePresenterWithBlock: (void(^ __nullable)()) block;

/**
  Override this methods to handle when presenter updated
*/
- (void)presenterNeedUpdate;

- (void)presenterDidLoad;

/**
  Functions
*/
- (void)configurePresenterForSubControllers;
- (void)addSubViewController:(UIViewController <FISubViewControllerProtocol>* __nonnull)childController withConfiguration: (void(^ __nullable)(UIView * __nonnull childView))configurationBlock;
- (void)removeSubViewController:(UIViewController <FISubViewControllerProtocol>* __nonnull)childController;


@end
