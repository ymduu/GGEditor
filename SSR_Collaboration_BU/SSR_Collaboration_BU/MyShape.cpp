//popopo

#include"MyShape.h"
#include"MyRectangle.h"
#include"MyCircle.h"
#include"MyAngledTriangle.h"
#include "ToolsLib.h"

bool MyShape::HitJudge(const MyShape *pshape, const Vector2D aMyPos, const Vector2D aOtherPos) {
	//ダウンキャストしてどのHitJudgeを呼べば良いかを判断する
	{
		const MyCircle *pCircle = dynamic_cast<const MyCircle *>(pshape);
		if (pCircle != nullptr) {
			return VHitJudge(pCircle,aMyPos,aOtherPos);

		}
	}
	{
		const MyRectangle *pRectangle = dynamic_cast<const MyRectangle *>(pshape);
		if (pRectangle != nullptr) {

			return VHitJudge(pRectangle, aMyPos, aOtherPos);

		}
	}
	{
		const MyAngledTriangle *pAngledTriangle = dynamic_cast<const MyAngledTriangle *>(pshape);
		if (pAngledTriangle != nullptr) {
			return VHitJudge(pAngledTriangle, aMyPos, aOtherPos);

		}
	}

	return false;
}

//当たり判定の実体
bool MyShape::HitJudge(const MyCircle *pshape1, const MyCircle *pshape2, const Vector2D aMyPos, const Vector2D aOtherPos) {
	if ((pshape1->r + pshape2->r)*(pshape1->r + pshape2->r) >= (aMyPos.x - aOtherPos.x)*(aMyPos.x - aOtherPos.x) + (aMyPos.y - aOtherPos.y)*(aMyPos.y - aOtherPos.y)) {
		return true;
	}
	return false;
}

bool MyShape::HitJudge(const MyCircle *pshape1, const MyRectangle *pshape2, const Vector2D aMyPos, const Vector2D aOtherPos) {
	return false;
}

bool MyShape::HitJudge(const MyCircle *pshape1, const MyAngledTriangle *pshape2, const Vector2D aMyPos, const Vector2D aOtherPos) {
	return false;
}

//当面は動くオブジェクトは円のみとするので今の所はfalseを返すままにしておきます
bool MyShape::HitJudge(const MyRectangle *pshape1, const MyRectangle *pshape2, const Vector2D aMyPos, const Vector2D aOtherPos) {
	return false;
}

bool MyShape::HitJudge(const MyRectangle *pshape1, const MyAngledTriangle *pshape2, const Vector2D aMyPos, const Vector2D aOtherPos) {
	return false;
}

bool MyShape::HitJudge(const MyAngledTriangle *pshape1, const MyAngledTriangle *pshape2, const Vector2D aMyPos, const Vector2D aOtherPos) {
	return false;
}

