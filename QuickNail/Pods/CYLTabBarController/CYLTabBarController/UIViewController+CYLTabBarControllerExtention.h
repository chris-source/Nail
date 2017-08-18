//
//  UIViewController+CYLTabBarControllerExtention.h
//  CYLTabBarController
//
//  v1.8.0 Created by 微博@iOS程序犭袁 ( http://weibo.com/luohanchenyilong/ ) on 16/2/26.
//  Copyright © 2016年 https://github.com/ChenYilong .All rights reserved.
//

#import <UIKit/UIKit.h>

typedef void (^CYLPopSelectTabBarChildViewControllerCompletion)(__kindof UIViewController *selectedTabBarChildViewController);

typedef void (^CYLPushOrPopCompletionHandler)(BOOL shouldPop,
                                              __kindof UIViewController *viewControllerPopTo,
                                              BOOL shouldPopSelectTabBarChildViewController,
                                              NSUInteger index
                                              );

typedef void (^CYLPushOrPopCallback)(NSArray<__kindof UIViewController *> *viewControllers, CYLPushOrPopCompletionHandler completionHandler);

@interface UIViewController (CYLTabBarControllerExtention)

/*!
 * Pop 到当前 `NavigationController` 的栈底，并改变 `TabBarController` 的 `selectedViewController` 属性，并将被选择的控制器作为返回值返回。
 @param index 需要选择的控制器在 `TabBar` 中的 index。
 @return 最终被选择的控制器。
 @attention 注意：方法中的参数和返回值都是 `UIViewController` 的子类，但并非 `UINavigationController` 的子类。
 */
- (UIViewController *)cyl_popSelectTabBarChildViewControllerAtIndex:(NSUInteger)index;

/*!
 * Pop 到当前 `NavigationController` 的栈底，并改变 `TabBarController` 的 `selectedViewController` 属性，并将被选择的控制器在 `Block` 回调中返回。
 @param index 需要选择的控制器在 `TabBar` 中的 index。
 @attention 注意：方法中的参数和返回值都是 `UIViewController` 的子类，但并非 `UINavigationController` 的子类。
 */
- (void)cyl_popSelectTabBarChildViewControllerAtIndex:(NSUInteger)index
                                           completion:(CYLPopSelectTabBarChildViewControllerCompletion)completion;

/*!
 * Pop 到当前 `NavigationController` 的栈底，并改变 `TabBarController` 的 `selectedViewController` 属性，并将被选择的控制器作为返回值返回。
 @param classType 需要选择的控制器所属的类。
 @return 最终被选择的控制器。
 @attention 注意：方法中的参数和返回值都是 `UIViewController` 的子类，但并非 `UINavigationController` 的子类。
 */
- (UIViewController *)cyl_popSelectTabBarChildViewControllerForClassType:(Class)classType;

/*!
 * Pop 到当前 `NavigationController` 的栈底，并改变 `TabBarController` 的 `selectedViewController` 属性，并将被选择的控制器在 `Block` 回调中返回。
 @param classType 需要选择的控制器所属的类。
 @attention 注意：方法中的参数和返回值都是 `UIViewController` 的子类，但并非 `UINavigationController` 的子类。
 */
- (void)cyl_popSelectTabBarChildViewControllerForClassType:(Class)classType
                                                completion:(CYLPopSelectTabBarChildViewControllerCompletion)completion;

/*!
 *@brief 如果当前的 `NavigationViewController` 栈中包含有准备 Push 到的目标控制器，可以选择 Pop 而非 Push。
 *@param viewController Pop 或 Push 到的“目标控制器”，由 completionHandler 的参数控制 Pop 和 Push 的细节。
 *@param animated Pop 或 Push 时是否带动画
 *@param callback 回调，如果传 nil，将进行 Push。callback 包含以下几个参数：
                  *@param viewControllers 表示与“目标控制器”相同类型的控制器；
                  *@param completionHandler 包含以下几个参数：
                                            *@param shouldPop 是否 Pop
                                            *@param viewControllerPopTo Pop 回的控制器
                                            *@param shouldPopSelectTabBarChildViewController 在进行 Push 行为之前，是否 Pop 到当前 `NavigationController` 的栈底。
                                                                                             可能的值如下：
                                                                                             NO 如果上一个参数为 NO，下一个参数 index 将被忽略。
                                                                                             YES 会根据 index 参数改变 `TabBarController` 的 `selectedViewController` 属性。
                                                                                             注意：该属性在 Pop 行为时不起作用。
                                             *@param index Pop 改变 `TabBarController` 的 `selectedViewController` 属性。
                                                           注意：该属性在 Pop 行为时不起作用。
                   */
- (void)cyl_pushOrPopToViewController:(UIViewController *)viewController
                             animated:(BOOL)animated
                             callback:(CYLPushOrPopCallback)callback;

@end