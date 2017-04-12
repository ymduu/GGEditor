//popopo

#include"MyShape.h"
#include"MyRectangle.h"
#include"MyCircle.h"
#include"MyAngledTriangle.h"

MyShape::HitInfo MyShape::HitJudge(const MyShape *pshape) {
	//ダウンキャストしてどのHitJudgeを呼べば良いかを判断する
	{
		const MyCircle *pCircle = dynamic_cast<const MyCircle *>(pshape);
		if (pCircle != nullptr) {
			return VHitJudge(pCircle);
		}
	}
	{
		const MyRectangle *pRectangle = dynamic_cast<const MyRectangle *>(pshape);
		if (pRectangle != nullptr) {
			return VHitJudge(pRectangle);
		}
	}
	{
		const MyAngledTriangle *pAngledTriangle = dynamic_cast<const MyAngledTriangle *>(pshape);
		if (pAngledTriangle != nullptr) {
			return VHitJudge(pAngledTriangle);
		}
	}

	return HitInfo(false);
}

//当たり判定の実体
MyShape::HitInfo MyShape::HitJudge(const MyCircle *pshape1, const MyCircle *pshape2) {
	return HitInfo(false);
}

MyShape::HitInfo MyShape::HitJudge(const MyCircle *pshape1, const MyRectangle *pshape2) {
	return HitInfo(false);
}

MyShape::HitInfo MyShape::HitJudge(const MyCircle *pshape1, const MyAngledTriangle *pshape2) {
	return HitInfo(false);
}

MyShape::HitInfo MyShape::HitJudge(const MyRectangle *pshape1, const MyRectangle *pshape2) {
	return HitInfo(false);
}

MyShape::HitInfo MyShape::HitJudge(const MyRectangle *pshape1, const MyAngledTriangle *pshape2) {
	return HitInfo(false);
}

MyShape::HitInfo MyShape::HitJudge(const MyAngledTriangle *pshape1, const MyAngledTriangle *pshape2) {
	return HitInfo(false);
}

