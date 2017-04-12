//popopo

#include"MyShape.h"
#include"MyRectangle.h"
#include"MyCircle.h"
#include"MyAngledTriangle.h"
#include "ToolsLib.h"

MyShape::HitInfo MyShape::HitJudge(const MyShape *pshape, const Vector2D aMyPos, const Vector2D aOtherPos) {
	//�_�E���L���X�g���Ăǂ�HitJudge���ĂׂΗǂ����𔻒f����
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

	return HitInfo(false);
}

//�����蔻��̎���
MyShape::HitInfo MyShape::HitJudge(const MyCircle *pshape1, const MyCircle *pshape2, const Vector2D aMyPos, const Vector2D aOtherPos) {
	if ((pshape1->r + pshape2->r)*(pshape1->r + pshape2->r) >= (aMyPos.x - aOtherPos.x)*(aMyPos.x - aOtherPos.x) + (aMyPos.y - aOtherPos.y)*(aMyPos.y - aOtherPos.y)) {
		return HitInfo(true);
	}
	return HitInfo(false);
}

MyShape::HitInfo MyShape::HitJudge(const MyCircle *pshape1, const MyRectangle *pshape2) {
	return HitInfo(false);
}

MyShape::HitInfo MyShape::HitJudge(const MyCircle *pshape1, const MyAngledTriangle *pshape2) {
	return HitInfo(false);
}

//���ʂ͓����I�u�W�F�N�g�͉~�݂̂Ƃ���̂ō��̏���false��Ԃ��܂܂ɂ��Ă����܂�
MyShape::HitInfo MyShape::HitJudge(const MyRectangle *pshape1, const MyRectangle *pshape2) {
	return HitInfo(false);
}

MyShape::HitInfo MyShape::HitJudge(const MyRectangle *pshape1, const MyAngledTriangle *pshape2) {
	return HitInfo(false);
}

MyShape::HitInfo MyShape::HitJudge(const MyAngledTriangle *pshape1, const MyAngledTriangle *pshape2) {
	return HitInfo(false);
}

