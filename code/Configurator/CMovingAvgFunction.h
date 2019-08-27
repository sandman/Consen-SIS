// 从类型库向导中用“添加类”创建的计算机生成的 IDispatch 包装类

#import "C:\Windows\\System32\\TeeChart8.ocx" no_namespace
// CMovingAvgFunction 包装类

class CMovingAvgFunction : public COleDispatchDriver
{
public:
	CMovingAvgFunction(){} // 调用 COleDispatchDriver 默认构造函数
	CMovingAvgFunction(LPDISPATCH pDispatch) : COleDispatchDriver(pDispatch) {}
	CMovingAvgFunction(const CMovingAvgFunction& dispatchSrc) : COleDispatchDriver(dispatchSrc) {}

	// 特性
public:

	// 操作
public:


	// IMovingAvgFunction 方法
public:
	BOOL get_Weighted()
	{
		BOOL result;
		InvokeHelper(0x1, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
		return result;
	}
	void put_Weighted(BOOL newValue)
	{
		static BYTE parms[] = VTS_BOOL ;
		InvokeHelper(0x1, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms, newValue);
	}

	// IMovingAvgFunction 属性
public:

};
