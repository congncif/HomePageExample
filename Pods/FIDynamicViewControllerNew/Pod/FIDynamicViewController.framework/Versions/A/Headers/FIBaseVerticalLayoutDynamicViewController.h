//
//  FIBaseVerticalLayoutDynamicViewController.h
//  FIDynamicViewController
//
//  Created by NGUYEN CHI CONG on 8/12/15.
//  Copyright (c) 2015 NGUYEN CHI CONG. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "FIBaseDynamicViewController.h"

@interface FIBaseVerticalLayoutDynamicViewController : FIBaseDynamicViewController

@property (nonatomic, strong) UIScrollView * __nonnull scrollView;

@property (nonatomic, readonly) NSMutableArray * __nullable subViewControllers;

@property (nonatomic) UIEdgeInsets defaultInset;

@property (nonatomic, assign) BOOL layoutSubControllerImmediately;
@property (atomic, assign) BOOL layoutWithAnimation;

@property (nonatomic, readonly, getter=isGenerating) BOOL generating;

@property (nonatomic, copy) NSString * __nullable animationType;
@property (nonatomic, copy) NSString * __nullable animationDirection;

/**
 *  Add subViewController to bottom
 *
 *  @param childController must be followed FISubViewControllerProtocol protocol
 */
- (void)addSubViewController:(UIViewController<FISubViewControllerProtocol> * __nonnull)childController;


/**
 *  Remove a subViewController
 *
 *  @param childController must be followed FISubViewControllerProtocol protocol
 */
- (void)removeSubViewController:(UIViewController <FISubViewControllerProtocol>* __nonnull)childController;

/**
 *  Insert a subViewController at index
 *
 *  @param childController must be followed FISubViewControllerProtocol protocol
 *  @param index           position childViewController which will be added
 */
- (void)insertSubViewController:(UIViewController <FISubViewControllerProtocol>* __nonnull)childController atIndex: (NSInteger)index;
/**
 *  Remove subViewController at index, do nothing if index is invalid
 *
 *  @param index position subViewController which will be removed
 */
- (void)removeSubViewControllerAtIndex: (NSInteger)index;

/**
 *  Remove all sub controllers in contents
 */
- (void)removeAllSubContents;

/**
 *  Remove all sub controllers include header & footer
 */
- (void)removeAllSubViewControllers;


/**
 *  Add header controller if needed, header is always on top
 *
 *  @param childController must be followed FISubViewControllerProtocol protocol, nil if want to remove header
 */
- (void)configureHeaderViewController: (UIViewController <FISubViewControllerProtocol>* __nullable)childController;

/**
 *  Add footer controller if needed, header is always on top
 *
 *  @param childController must be followed FISubViewControllerProtocol protocol, nil if want to remove footer
 */
- (void)configureFooterViewController: (UIViewController <FISubViewControllerProtocol>* __nullable)childController;

- (void)layoutSubViewControllers;

/**
 *  Method to refresh layout
 */
- (void)invalidDyamicLayout;

/**
 *  Method to refresh layout
 *
 *  @param animated force animating when refresh layout
 */
- (void)invalidDyamicLayoutAnimated: (BOOL)animated;


/**
 *  Refresh layout with call back
 *
 *  @param completion call back hanlder when refresh layout finished
 */
- (void)invalidDyamicLayoutAnimatedWithCompletion: (void (^ __nullable)(BOOL finished))completion;

/**
 *  Refresh layout of subViewControllers from controller to bottom
 *
 *  @param controller
 */
- (void)layoutSubViewController: (id __nonnull)controller;
- (void)layoutSubViewController: (id __nonnull)controller animated: (BOOL)animated;



/**
 *  Set up subviewcontrollers with main block run in background
 *
 *  @param startBlock    perform startBlock before generate subViewControllers
 *  @param mainBlock     subViewControllers need to be added in here
 *  @param finishedBlock perform finishedBlock after generate subViewControllers
 */
- (void)generateSubControllersWithBeignBlock: (void(^ __nullable)())startBlock
                                   mainBlock: (void(^ __nullable)())mainBlock
                               finishedBlock: (void(^ __nullable)())finishedBlock;
- (void)generateSubControllersWithBlock: (void(^ __nullable)())block;



/// CUSTOM
/**
 *  Methods should be override to custom in subclass
 *
 */
/** Run in main thread */
- (void)beginGenerateAndConfigureSubViewControllers;

/** Run in async for generating sub view controllers */
- (void)generateAndConfigureSubViewControllers;

/** Run in main thread */
- (void)finishGenerateAndConfigureSubViewControllers;

+ (void)setClassForScrollView: (Class __nonnull)ScrollViewClass;
+ (Class _Nonnull)classForScrollView;




@end
