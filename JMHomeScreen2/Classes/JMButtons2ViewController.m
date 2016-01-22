//
//  JMButtons2ViewController.m
//  JMHomeScreen2
//
//  Created by FOLY on 1/22/16.
//  Copyright © 2016 FOLY. All rights reserved.
//

#import "JMButtons2ViewController.h"
#import "NSArray+iF.h"

@interface JMButtons2ViewController ()<UICollectionViewDataSource, UICollectionViewDelegate, UICollectionViewDelegateFlowLayout>

@property (nonatomic, weak) IBOutlet UICollectionView *collectionView;


@end

@implementation JMButtons2ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view.
    self.autoReduceToFitContent = YES;
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

- (CGFloat)heightForLayout{
    
    return self.collectionView.contentSize.height;
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
    cell.backgroundColor = [self randomColor];
    return cell;
}

//MARK: CollectionView Delegate
- (void)collectionView:(UICollectionView *)collectionView didSelectItemAtIndexPath:(NSIndexPath *)indexPath{
    
}


- (CGSize)collectionView:(UICollectionView *)collectionView layout:(nonnull UICollectionViewLayout *)collectionViewLayout sizeForItemAtIndexPath:(nonnull NSIndexPath *)indexPath{
    
    CGFloat height = [UIScreen mainScreen].bounds.size.height;
    height = height - self.deficit;
    
    height = height *1.0f/5.0f;
    CGFloat width = [UIScreen mainScreen].bounds.size.width / self.numberOfColumnsInLine;
    
    return CGSizeMake(width, height);
}

- (UIColor *)randomColor {
    CGFloat hue = ( arc4random() % 256 / 256.0 );  //  0.0 to 1.0
    CGFloat saturation = ( arc4random() % 128 / 256.0 ) + 0.5;  //  0.5 to 1.0, away from white
    CGFloat brightness = ( arc4random() % 128 / 256.0 ) + 0.5;  //  0.5 to 1.0, away from black
    UIColor *color = [UIColor colorWithHue:hue saturation:saturation brightness:brightness alpha:1];
    
    return color;
}



@end
