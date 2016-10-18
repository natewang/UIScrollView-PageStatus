# UIScrollView-PageStatus
对[DZNEmptyDataSet](https://github.com/dzenbot/DZNEmptyDataSet)的一个封装，项目中页面统一管理.
```
/**
 *  当前页面状态
 */
@property (nonatomic, assign) PageStatus currentPageStatus;

/**
 *  如果请求成功，空数据，显示提示
 */
@property (nonatomic, strong) NSString *succeedEmptyStr;

/**
 *  如果请求成功，空数据，显示的图片
 */
@property (nonatomic ,strong) UIImage *succeedEmptyImage;

/**
 *  空页面点击，刷新block
 */
@property (nonatomic, copy) EmptyViewTapBlock emptyViewTapBlock;
```
分离了DZNEmptyDataSet的delegate到这个文件，可以进行一些自己的配置，达到工程中页面的统一设置。
```
@weakify(self);
    [self.mainTableView setEmptyViewTapBlock:^{
        @strongify(self);
        [self fetchClue];
    }];
    self.mainTableView.succeedEmptyStr = @"我的收藏为空";
    self.mainTableView.succeedEmptyImage = [UIImage imageNamed:@"collectionEmpty"];
```
记得delegate
```
        _mainTableView.emptyDataSetSource = _mainTableView;
        _mainTableView.emptyDataSetDelegate = _mainTableView;
```
