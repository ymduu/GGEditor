#include"MyShape.h"
#include"MyRectangle.h"
#include"MyCircle.h"
#include"MyAngledTriangle.h"
#include "ToolsLib.h"

MyShape::HitInfo MyShape::HitJudge(const MyShape *pshape, const Vector2D aMyPos, const Vector2D aOtherPos)const {
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

	return HitInfo(false,Vector2D(0.0f,0.0f));
}

//�����蔻��̎���
MyShape::HitInfo MyShape::HitJudge(const MyCircle *pshape1, const MyCircle *pshape2, const Vector2D aMyPos, const Vector2D aOtherPos) {
	if ((pshape1->r + pshape2->r)*(pshape1->r + pshape2->r) >= (aMyPos.x - aOtherPos.x)*(aMyPos.x - aOtherPos.x) + (aMyPos.y - aOtherPos.y)*(aMyPos.y - aOtherPos.y)) {
		//�߂荞�ݗʂ��v�Z
		float fixSize = (pshape1->r+pshape2->r-(aMyPos - aOtherPos).size());
		//�␳�x�N�g�����v�Z(���������̃x�N�g����Ԃ��A����𑫂����Ƃŕ␳���ł���)
		Vector2D fixVec = (aMyPos - aOtherPos).norm()*fixSize;
		return HitInfo(true,fixVec);
	}
	return HitInfo(false,Vector2D(0.0f,0.0f));
}

MyShape::HitInfo MyShape::HitJudge(const MyCircle *pshape1, const MyRectangle *pshape2, const Vector2D aMyPos, const Vector2D aOtherPos) {
	//�ŋߖT�_�����߂�
	Vector2D nearestPoint = pshape2->GetNearestPoint(aOtherPos, aMyPos);
	if ((aMyPos - nearestPoint).sqSize() < pshape1->r*pshape1->r) {
		//�~�̒��S����ŋߖT�_�܂ł̋���**2<���a**2�Ȃ�Փ˂��Ă���
		//�߂荞�ݗʂ��v�Z
		float fixSize = pshape1->r-(aMyPos - nearestPoint).size();
		//�␳�x�N�g�����v�Z(���������̃x�N�g����Ԃ��A����𑫂����Ƃŕ␳���ł���)
		Vector2D fixVec = (aMyPos - nearestPoint).norm()*fixSize*0.97;
		return HitInfo(true,fixVec);
	}

	return HitInfo(false, Vector2D(0.0f, 0.0f));
}

MyShape::HitInfo MyShape::HitJudge(const MyCircle *pshape1, const MyAngledTriangle *pshape2, const Vector2D aMyPos, const Vector2D aOtherPos) {
	Vector2D nearestPoint = pshape2->GetNearestPoint(aOtherPos, aMyPos);
	if ((aMyPos - nearestPoint).sqSize() < pshape1->r*pshape1->r) {
		//�~�̒��S����ŋߖT�_�܂ł̋���**2<���a**2�Ȃ�Փ˂��Ă���
		//�߂荞�ݗʂ��v�Z
		float fixSize = pshape1->r - (aMyPos - nearestPoint).size();
		//�␳�x�N�g�����v�Z(���������̃x�N�g����Ԃ��A����𑫂����Ƃŕ␳���ł���)
		Vector2D fixVec = (aMyPos - nearestPoint).norm()*fixSize;
		return HitInfo(true, fixVec);
	}
	return HitInfo(false, Vector2D(0.0f, 0.0f));
}

//���ʂ͓����I�u�W�F�N�g�͉~�݂̂Ƃ���̂ō��̏���false��Ԃ��܂܂ɂ��Ă����܂�
MyShape::HitInfo MyShape::HitJudge(const MyRectangle *pshape1, const MyRectangle *pshape2, const Vector2D aMyPos, const Vector2D aOtherPos) {
	return HitInfo(false, Vector2D(0.0f, 0.0f));
}

MyShape::HitInfo MyShape::HitJudge(const MyRectangle *pshape1, const MyAngledTriangle *pshape2, const Vector2D aMyPos, const Vector2D aOtherPos) {
	return HitInfo(false, Vector2D(0.0f, 0.0f));
}

MyShape::HitInfo MyShape::HitJudge(const MyAngledTriangle *pshape1, const MyAngledTriangle *pshape2, const Vector2D aMyPos, const Vector2D aOtherPos) {
	return HitInfo(false, Vector2D(0.0f, 0.0f));
}

