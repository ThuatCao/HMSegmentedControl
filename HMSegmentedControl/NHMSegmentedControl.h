//
//  NHMSegmentedControl.h
//  NHMSegmentedControl
//
//  Created by Hesham Abd-Elmegid on 23/12/12.
//  Copyright (c) 2012-2015 Hesham Abd-Elmegid. All rights reserved.
//

#import <UIKit/UIKit.h>

@class NHMSegmentedControl;

typedef void (^IndexChangeBlock)(NSInteger index);
typedef NSAttributedString *(^NHMTitleFormatterBlock)(NHMSegmentedControl *segmentedControl, NSString *title, NSUInteger index, BOOL selected);

typedef NS_ENUM(NSInteger, NHMSegmentedControlSelectionStyle) {
    NHMSegmentedControlSelectionStyleTextWidthStripe, // Indicator width will only be as big as the text width
    NHMSegmentedControlSelectionStyleFullWidthStripe, // Indicator width will fill the whole segment
    NHMSegmentedControlSelectionStyleBox, // A rectangle that covers the whole segment
    NHMSegmentedControlSelectionStyleArrow, // An arrow in the middle of the segment pointing up or down depending on `NHMSegmentedControlSelectionIndicatorLocation`
    NNHMSegmentedControlSelectionStyleMidleText,
    NNHMSegmentedControlSelectionStyleLeftText
};

typedef NS_ENUM(NSInteger, NHMSegmentedControlSelectionIndicatorLocation) {
    NHMSegmentedControlSelectionIndicatorLocationUp,
    NHMSegmentedControlSelectionIndicatorLocationDown,
	NHMSegmentedControlSelectionIndicatorLocationNone // No selection indicator
};

typedef NS_ENUM(NSInteger, NHMSegmentedControlSegmentWidthStyle) {
    NHMSegmentedControlSegmentWidthStyleFixed, // Segment width is fixed
    NHMSegmentedControlSegmentWidthStyleDynamic, // Segment width will only be as big as the text width (including inset)
};

typedef NS_OPTIONS(NSInteger, NHMSegmentedControlBorderType) {
    NHMSegmentedControlBorderTypeNone = 0,
    NHMSegmentedControlBorderTypeTop = (1 << 0),
    NHMSegmentedControlBorderTypeLeft = (1 << 1),
    NHMSegmentedControlBorderTypeBottom = (1 << 2),
    NHMSegmentedControlBorderTypeRight = (1 << 3)
};

enum {
    NHMSegmentedControlNoSegment = -1   // Segment index for no selected segment
};

typedef NS_ENUM(NSInteger, NHMSegmentedControlType) {
    NHMSegmentedControlTypeText,
    NHMSegmentedControlTypeImages,
	NHMSegmentedControlTypeTextImages
};

typedef NS_ENUM(NSInteger, NHMSegmentedControlImagePosition) {
    NHMSegmentedControlImagePositionBehindText,
    NHMSegmentedControlImagePositionLeftOfText,
    NHMSegmentedControlImagePositionRightOfText,
    NHMSegmentedControlImagePositionAboveText,
    NHMSegmentedControlImagePositionBelowText
};

@interface NHMSegmentedControl : UIControl

@property (nonatomic, strong) NSArray<NSString *> *sectionTitles;
@property (nonatomic, strong) NSArray<UIImage *> *sectionImages;
@property (nonatomic, strong) NSArray<UIImage *> *sectionSelectedImages;

@property (nonatomic, assign) CGFloat indicatorWidth;

/**
 Provide a block to be executed when selected index is changed.
 
 Alternativly, you could use `addTarget:action:forControlEvents:`
 
 
 */
@property (nonatomic, copy) IndexChangeBlock indexChangeBlock;

/**
 Used to apply custom text styling to titles when set.
 
 When this block is set, no additional styling is applied to the `NSAttributedString` object returned from this block.
 */
@property (nonatomic, copy) NHMTitleFormatterBlock titleFormatter;

/**
 Text attributes to apply to item title text.
 */
@property (nonatomic, strong) NSDictionary *titleTextAttributes UI_APPEARANCE_SELECTOR;

/*
 Text attributes to apply to selected item title text.
 
 Attributes not set in this dictionary are inherited from `titleTextAttributes`.
 */
@property (nonatomic, strong) NSDictionary *selectedTitleTextAttributes UI_APPEARANCE_SELECTOR;

/**
 Segmented control background color.
 
 Default is `[UIColor whiteColor]`
 */
@property (nonatomic, strong) UIColor *backgroundColor UI_APPEARANCE_SELECTOR;

/**
 Color for the selection indicator stripe
 
 Default is `R:52, G:181, B:229`
 */
@property (nonatomic, strong) UIColor *selectionIndicatorColor UI_APPEARANCE_SELECTOR;

/**
 Color for the selection indicator box
 
 Default is selectionIndicatorColor
 */
@property (nonatomic, strong) UIColor *selectionIndicatorBoxColor UI_APPEARANCE_SELECTOR;

/**
 Color for the vertical divider between segments.
 
 Default is `[UIColor blackColor]`
 */
@property (nonatomic, strong) UIColor *verticalDividerColor UI_APPEARANCE_SELECTOR;

/**
 Opacity for the seletion indicator box.
 
 Default is `0.2f`
 */
@property (nonatomic) CGFloat selectionIndicatorBoxOpacity;

/**
 Width the vertical divider between segments that is added when `verticalDividerEnabled` is set to YES.
 
 Default is `1.0f`
 */
@property (nonatomic, assign) CGFloat verticalDividerWidth;

/**
 Specifies the style of the control
 
 Default is `NHMSegmentedControlTypeText`
 */
@property (nonatomic, assign) NHMSegmentedControlType type;

/**
 Specifies the style of the selection indicator.
 
 Default is `NHMSegmentedControlSelectionStyleTextWidthStripe`
 */
@property (nonatomic, assign) NHMSegmentedControlSelectionStyle selectionStyle;

/**
 Specifies the style of the segment's width.
 
 Default is `NHMSegmentedControlSegmentWidthStyleFixed`
 */
@property (nonatomic, assign) NHMSegmentedControlSegmentWidthStyle segmentWidthStyle;

/**
 Specifies the location of the selection indicator.
 
 Default is `NHMSegmentedControlSelectionIndicatorLocationUp`
 */
@property (nonatomic, assign) NHMSegmentedControlSelectionIndicatorLocation selectionIndicatorLocation;

/*
 Specifies the border type.
 
 Default is `NHMSegmentedControlBorderTypeNone`
 */
@property (nonatomic, assign) NHMSegmentedControlBorderType borderType;

/**
 Specifies the image position relative to the text. Only applicable for NHMSegmentedControlTypeTextImages
 
 Default is `NHMSegmentedControlImagePositionBehindText`
 */
@property (nonatomic) NHMSegmentedControlImagePosition imagePosition;

/**
 Specifies the distance between the text and the image. Only applicable for NHMSegmentedControlTypeTextImages
 
 Default is `0,0`
 */
@property (nonatomic) CGFloat textImageSpacing;

/**
 Specifies the border color.
 
 Default is `[UIColor blackColor]`
 */
@property (nonatomic, strong) UIColor *borderColor;

/**
 Specifies the border width.
 
 Default is `1.0f`
 */
@property (nonatomic, assign) CGFloat borderWidth;

/**
 Default is YES. Set to NO to deny scrolling by dragging the scrollView by the user.
 */
@property(nonatomic, getter = isUserDraggable) BOOL userDraggable;

/**
 Default is YES. Set to NO to deny any touch events by the user.
 */
@property(nonatomic, getter = isTouchEnabled) BOOL touchEnabled;

/**
 Default is NO. Set to YES to show a vertical divider between the segments.
 */
@property(nonatomic, getter = isVerticalDividerEnabled) BOOL verticalDividerEnabled;

@property (nonatomic, getter=shouldStretchSegmentsToScreenSize) BOOL stretchSegmentsToScreenSize;

/**
 Index of the currently selected segment.
 */
@property (nonatomic, assign) NSInteger selectedSegmentIndex;

/**
 Height of the selection indicator. Only effective when `NHMSegmentedControlSelectionStyle` is either `NHMSegmentedControlSelectionStyleTextWidthStripe` or `NHMSegmentedControlSelectionStyleFullWidthStripe`.
 
 Default is 5.0
 */
@property (nonatomic, readwrite) CGFloat selectionIndicatorHeight;

/**
 Edge insets for the selection indicator.
 NOTE: This does not affect the bounding box of NHMSegmentedControlSelectionStyleBox
 
 When NHMSegmentedControlSelectionIndicatorLocationUp is selected, bottom edge insets are not used
 
 When NHMSegmentedControlSelectionIndicatorLocationDown is selected, top edge insets are not used
 
 Defaults are top: 0.0f
             left: 0.0f
           bottom: 0.0f
            right: 0.0f
 */
@property (nonatomic, readwrite) UIEdgeInsets selectionIndicatorEdgeInsets;

/**
 Inset left and right edges of segments.
 
 Default is UIEdgeInsetsMake(0, 5, 0, 5)
 */
@property (nonatomic, readwrite) UIEdgeInsets segmentEdgeInset;

@property (nonatomic, readwrite) UIEdgeInsets enlargeEdgeInset;

/**
 Default is YES. Set to NO to disable animation during user selection.
 */
@property (nonatomic) BOOL shouldAnimateUserSelection;

- (id)initWithSectionTitles:(NSArray<NSString *> *)sectiontitles;
- (id)initWithSectionImages:(NSArray<UIImage *> *)sectionImages sectionSelectedImages:(NSArray<UIImage *> *)sectionSelectedImages;
- (instancetype)initWithSectionImages:(NSArray<UIImage *> *)sectionImages sectionSelectedImages:(NSArray<UIImage *> *)sectionSelectedImages titlesForSections:(NSArray<NSString *> *)sectiontitles;
- (void)setSelectedSegmentIndex:(NSUInteger)index animated:(BOOL)animated;
- (void)setIndexChangeBlock:(IndexChangeBlock)indexChangeBlock;
- (void)setTitleFormatter:(NHMTitleFormatterBlock)titleFormatter;

@end
