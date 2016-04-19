//
//  FIBaseVerticalLayoutDynamicViewController.h
//  FIDynamicViewController
//
//  Created by NGUYEN CHI CONG on 8/12/15.
//  Copyright (c) 2015 NGUYEN CHI CONG. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "FIBaseDynamicViewController.h"

static Class __nullable FIScrollView;

@interface FIBaseVerticalLayoutDynamicViewController : FIBaseDynamicViewController

@property (nonatomic, strong) UIScrollView * __nonnull scrollView;

@property (nonatomic, readonly) NSMutableArray * __nullable subViewControllers;

@property (nonatomic) UIEdgeInsets defaultInset;

@property (nonatomic, assign) BOOL layoutSubControllerImmediately;
@property (nonatomic, assign) BOOL layoutWithAnimation;

@property (nonatomic, readonly, getter=isGenerating) BOOL generating;

@property (nonatomic, copy) NSString * __nullable animationType;
@property (nonatomic, copy) NSString * __nullable animationDirection;

/**
 *
 *  Functions
 *
 **/
- (void)pushSubViewController:(UIViewController<FISubViewControllerProtocol> * __nonnull)childController;
- (void)popSubViewController:(UIViewController <FISubViewControllerProtocol>* __nonnull)childController ;

- (void)pushSubViewController:(UIViewController <FISubViewControllerProtocol>* __nonnull)childController insertAtIndex: (NSInteger)index ;
- (void)popSubViewControllerAtIndex: (NSInteger)index ;

- (void)prepareInBackgroundAddSubController: (UIViewController <FISubViewControllerProtocol> * __nonnull(^ __nonnull)(id __nullable parameters))block withParameters: (id __nullable)paramters;

/** Remove all sub controllers in contents */
- (void)popAllSubContents;
/** Remove all sub controllers include header & footer */
- (void)popAllSubViewControllers;

/** configure header | footer = nil if want to remove it */
- (void)configureHeaderViewController: (UIViewController <FISubViewControllerProtocol>* __nullable)childController;
- (void)configureFooterViewController: (UIViewController <FISubViewControllerProtocol>* __nullable)childController;

- (void)layoutSubViewControllers;

- (void)invalidDyamicLayout;
- (void)invalidDyamicLayoutAnimated: (BOOL)animated;

- (void)layoutSubViewController: (id __nonnull)controller;
- (void)layoutSubViewController: (id __nonnull)controller animated: (BOOL)animated;
- (void)invalidDyamicLayoutAnimatedWithCompletion: (void (^ __nullable)(BOOL finished))completion;

/** Set up subviewcontrollers with main block run in background */
- (void)generateSubControllersWithBeignBlock: (void(^ __nullable)())startBlock
                                   mainBlock: (void(^ __nullable)())mainBlock
                               finishedBlock: (void(^ __nullable)())finishedBlock;
- (void)generateSubControllersWithBlock: (void(^ __nullable)())block;

/**
 *
 *  Override this method to custom
 *
 **/
/** Run in main thread */
- (void)beginGenerateAndConfigureSubViewControllers;

/** Run in background for generating sub view controllers */
- (void)generateAndConfigureSubViewControllers;

/** Run in main thread */
- (void)finishGenerateAndConfigureSubViewControllers;

+ (void)setClassForScrollView: (Class __nonnull)ScrollViewClass;
+ (Class _Nonnull)classForScrollView;

@end
