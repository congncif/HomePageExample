//
//  JMSlideShow2ViewController.m
//  JMHomeScreen2
//
//  Created by FOLY on 1/22/16.
//  Copyright © 2016 FOLY. All rights reserved.
//

#import "JMSlideShow2ViewController.h"

#import "UIColor+iF.h"

@interface JMSlideShow2ViewController () <UICollectionViewDataSource, UICollectionViewDelegate, UICollectionViewDelegateFlowLayout>

@property (nonatomic, weak) IBOutlet UICollectionView *collectionView;
@property (weak, nonatomic) IBOutlet UIPageControl *pageControl;

@end

@implementation JMSlideShow2ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view
    
}

- (void)viewWillAppear:(BOOL)animated{
    [super viewWillAppear:animated];
    [self.collectionView.collectionViewLayout invalidateLayout];
}

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

- (CGFloat)heightForLayout{
    
    CGFloat height = [UIScreen mainScreen].bounds.size.height;
    return height *2.0f/5.0f;
}


//MARK: CollectionView Datasource
- (NSInteger)numberOfSectionsInCollectionView:(UICollectionView *)collectionView{
    return 1;
}

- (NSInteger)collectionView:(UICollectionView *)collectionView numberOfItemsInSection:(NSInteger)section{
    
    self.pageControl.numberOfPages = 3;
    return 3;
}

- (UICollectionViewCell *)collectionView:(UICollectionView *)collectionView cellForItemAtIndexPath:(NSIndexPath *)indexPath{
    UICollectionViewCell *cell = [collectionView dequeueReusableCellWithReuseIdentifier:@"Cell" forIndexPath:indexPath];
    cell.backgroundColor = [UIColor randomColor];
    return cell;
}

//MARK: CollectionView Delegate
- (void)collectionView:(UICollectionView *)collectionView didSelectItemAtIndexPath:(NSIndexPath *)indexPath{
    
}

- (CGSize)collectionView:(UICollectionView *)collectionView layout:(nonnull UICollectionViewLayout *)collectionViewLayout sizeForItemAtIndexPath:(nonnull NSIndexPath *)indexPath{
    
    return CGSizeMake([UIScreen mainScreen].bounds.size.width, self.heightForLayout);
}

- (void)scrollViewDidEndDecelerating:(UIScrollView *)scrollView {
    CGPoint offet = scrollView.contentOffset;
    
    NSInteger page = offet.x / self.collectionView.frame.size.width;
    self.pageControl.currentPage = page;
}

@end
