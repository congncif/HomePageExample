//
//  FIDynamicPresenter.h
//  StoryboardDemo
//
//  Created by NGUYEN CHI CONG on 8/7/15.
//  Copyright (c) 2015 NGUYEN CHI CONG. All rights reserved.
//

@protocol FIDynamicPresenterProtocol <NSObject>

- (void)updatePresenterWithBlock: (void(^)()) block observer: (id)observer;

@end
