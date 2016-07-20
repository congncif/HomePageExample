//
//  FIBaseDynamicViewController.h
//  FIDynamicViewController
//
//  Created by NGUYEN CHI CONG on 8/7/15.
//  Copyright (c) 2015 NGUYEN CHI CONG. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "FIDynamicViewControllerProtocol.h"
#import "FIDynamicPresenterProtocol.h"

@interface FIBaseDynamicViewController : UIViewController<FIDynamicViewControllerProtocol>

/**
  Model for storing data model in view controller
*/
@property (nonatomic, readonly) id <FIDynamicModelProtocol>__nullable dynamicModel;

- (void)setDynamicPresenterModel:(id <FIDynamicModelProtocol>_Nullable)dynamicModel;


/**
  Call this method to update model presenter
*/
- (void)updatePresenterWithBlock: (void(^ __nullable)()) block;
- (void)updatePresenterProperty:(SEL __nonnull) selector withBlock:(void(^ __nullable)( id __nullable value)) block;

/**
  Functions
*/
- (void)configurePresenterForSubControllers;
- (void)addSubViewController:(UIViewController <FISubViewControllerProtocol>* __nonnull)childController withConfiguration: (void(^ __nullable)(UIView * __nonnull childView))configurationBlock;
- (void)removeSubViewController:(UIViewController <FISubViewControllerProtocol>* __nonnull)childController;





#pragma mark - Override
/*------------------------------------------------------*/
/**
 Override this methods to handle when presenter updated
 */
- (void)presenterNeedUpdate;

- (void)presenterDidLoad;

- (void)presenterChangedValue: (id __nullable)value keyPath:(NSString * __nonnull)keyPath;


#pragma mark - deprecated
/*------------------------------------------------------*/
- (void)subViewControllerNeedUpdateLayout:(id<FISubViewControllerProtocol> __nullable) subViewController animated:(BOOL)animated __attribute__((deprecated("This method has been deprecated and will be removed in laster version. Please use subViewControllerNeedUpdateLayout: instead.")));

@end
