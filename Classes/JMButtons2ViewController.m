//
//  JMButtons2ViewController.m
//  JMHomeScreen2
//
//  Created by FOLY on 1/22/16.
//  Copyright © 2016 FOLY. All rights reserved.
//

#import "JMButtons2ViewController.h"

#import "NSArray+iF.h"
#import "UIColor+iF.h"
#import "CustomModel.h"

@interface JMButtons2ViewController ()<UICollectionViewDataSource, UICollectionViewDelegate, UICollectionViewDelegateFlowLayout>

@property (nonatomic, weak) IBOutlet UICollectionView *collectionView;


@end

@implementation JMButtons2ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view.
    self.autoReduceToFitContent = YES;
    
#warning - Guide for fitting content
    /**
     *  Set up view for fit content in subview controller
     */
    self.fitContentView = self.collectionView;
}

- (NSInteger)numberOfColumnsInLine{
    if (_numberOfColumnsInLine <= 0 || _numberOfColumnsInLine > 3) {
        return 1;
    }
    return _numberOfColumnsInLine;
}

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

//MARK: CollectionView Datasource
- (NSInteger)numberOfSectionsInCollectionView:(UICollectionView *)collectionView{
    return 1;
}

- (NSInteger)collectionView:(UICollectionView *)collectionView numberOfItemsInSection:(NSInteger)section{
    
    NSInteger count = 10;
    
    if (self.autoReduceToFitContent) {
        return reduceCount(count, self.numberOfColumnsInLine);
    }else{
        return count;
    }
}

- (UICollectionViewCell *)collectionView:(UICollectionView *)collectionView cellForItemAtIndexPath:(NSIndexPath *)indexPath{
    
    NSString *identifier = @"Cell";
    if (self.numberOfColumnsInLine == 1) {
        identifier = @"CellX";
    }
    
    UICollectionViewCell *cell = [collectionView dequeueReusableCellWithReuseIdentifier:identifier forIndexPath:indexPath];
    cell.backgroundColor = [UIColor randomColor];
    return cell;
}

//MARK: CollectionView Delegate
- (void)collectionView:(UICollectionView *)collectionView didSelectItemAtIndexPath:(NSIndexPath *)indexPath{
    
#warning SA: Step 1
    /**
     *  SEND ACTION TO CONTAINER VIEW CONTROLLER
     */
    id info = @{
                @"command": @"updateTitle",
                @"title": @"New Title"
                };
    
    [self.containerController subViewController:self sentActionWithInfo:info];
    
    
#warning UM: Step 1
    /**
     *  Will update dynamic model & send action to update UI if needed
     */
    __block CustomModel *model = (CustomModel *)self.dynamicModel;
    [self updatePresenterProperty:@selector(title) withBlock:^(id  _Nullable value) {
        model.title = @"new title from updating presenter";
    }];
    
}

- (CGSize)collectionView:(UICollectionView *)collectionView layout:(nonnull UICollectionViewLayout *)collectionViewLayout sizeForItemAtIndexPath:(nonnull NSIndexPath *)indexPath{
    
    CGFloat height = [UIScreen mainScreen].bounds.size.height;
    height = height - self.deficit;
    
    height = height *1.0f/5.0f;
    CGFloat width = [UIScreen mainScreen].bounds.size.width / self.numberOfColumnsInLine;
    
    return CGSizeMake(width, height);
}

#warning AS: Step 2
/**
 *  Receive ACTION From Other sub view controller
 */
- (BOOL)receiveActionWithInfo: (id)actionInfo {
    NSLog(@"Action info: %@", actionInfo);
    return YES;
}



@end
