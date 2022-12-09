#pragma once
#include <iostream>
#include <math.h>

template <class T>
class CPoint {
private:
	T posX;
	T posY;
	T posZ;
public:
	explicit CPoint(void) : posX(0), posY(0), posZ(0) {}
	explicit CPoint(const T x, const T y, const T z) : posX(x), posY(y), posZ(z) {}
	//explicit CPoint(const CPoint<T>& cpoint) : posX(cpoint.x), posY(cpoint.y), posZ(cpoint.z) {}

	~CPoint(void) = default;

	/**
	* @brief ���W��\������
	*/
	void ShowPosition(void) {
		std::cout << "X���W: " << this->posX << std::endl;
		std::cout << "Y���W: " << this->posY << std::endl;
		std::cout << "Z���W: " << this->posZ << std::endl;
		std::cout << std::endl;
	}

	/**
	* @brief 2�_�Ԃ̍��W�̍���\������
	* @param p �����𑪒肷��ׂ̂�����̍��W(CPoint�N���X)
	*/
	void getDistance(const CPoint<T>& p) {
		const T diffX = this->posX - p.posX;
		const T diffY = this->posY - p.posY;
		const T diffZ = this->posZ - p.posZ;

		std::cout << "1�_�ڂ�X���W: " << this->posX << "\t2�_�ڂ�X���W: " << p.posX << "\t��: " << diffX << std::endl;
		std::cout << "1�_�ڂ�Y���W: " << this->posY << "\t2�_�ڂ�Y���W: " << p.posY << "\t��: " << diffY << std::endl;
		std::cout << "1�_�ڂ�Z���W: " << this->posZ << "\t2�_�ڂ�Z���W: " << p.posZ << "\t��: " << diffZ << std::endl;

		const T diff = sqrt(diffX * diffX + diffY * diffY + diffZ * diffZ);
		std::cout << "����: " << diff << std::endl;
		std::cout << std::endl;
	}

	/**
	* @brief �w�肵�����Ԃ������R����������
	*		�܂��w�肵�����Ԃƍ��W��\������
	* @param milliSecond ���R�������鎞��(ms)
	* @param gravitationalAcceleration �d�͉����x(�����l 9.80665f)
	*/
	void freeFall(const float milliSecond, const float gravitationalAcceleration = 9.80665f) {
		const T prePosY = this->posY;
		const float t = milliSecond / 1000.0f;
		this->posY -= 0.5f * gravitationalAcceleration * t * t;
		std::cout << "������������: " << milliSecond << "ms" << std::endl;
		std::cout << "������������: " << prePosY - this->posY << std::endl;
		std::cout << std::endl;
	}

	/**
	* @brief �w�肵�������Ő^��ɓ������ꍇ�A�d�͗������������W���ړ�������
	*		�܂��w�肵�����Ԏ��̍��W�Ƒ��x��\������
	* @param milliSecond ���W�Ƒ��x���擾���鎞��(ms)
	* @param initialVelocity ����
	* @param gravitationalAcceleration �d�͉����x(�����l 9.80665f)
	*/
	void verticalThrowUp(const float milliSecond, const float initialVelocity, const float gravitationalAcceleration = 9.80665f) {
		const T prePosY = this->posY;
		const float t = milliSecond / 1000.0f;
		const auto add = (initialVelocity * t) - (0.5f * gravitationalAcceleration * t * t);
		const auto vel = initialVelocity + gravitationalAcceleration * t;
		this->posY += add;
		std::cout << "����: " << initialVelocity << "m/s" << std::endl;
		std::cout << "����: " << milliSecond << "ms" << std::endl;
		std::cout << "����: " << add << std::endl;
		std::cout << "���x: " << vel << std::endl;
		std::cout << std::endl;
	}

	// �ȉ�operator�֘A

	/**
	* @brief ���W��������
	* @param p
	* @return
	*/
	const CPoint<T> operator=(const CPoint<T>& p) {
		this->posX = p.posX;
		this->posY = p.posY;
		this->posZ = p.posZ;
		return *this;
	}
	const CPoint<T> operator+(const CPoint<T>& add) const {
		return CPoint<T>(this->posX + add.posX, this->posY + add.posY, this->posZ + add.posZ);
	}
	const CPoint<T> operator-(const CPoint<T>& sub) const {
		return CPoint<T>(this->posX - sub.posX, this->posY - sub.posY, this->posZ - sub.posZ);
	}
	void operator+=(const CPoint<T>& add) {
		this->posX += add.posX;
		this->posY += add.posY;
		this->posZ += add.posZ;
	}
	void operator-=(const CPoint<T>& sub) {
		this->posX -= sub.posX;
		this->posY -= sub.posY;
		this->posZ -= sub.posZ;
	}
	void operator*=(const T add) {
		this->posX *= add;
		this->posY *= add;
		this->posZ *= add;
	}
	void operator/=(const T div) {
		if (div == 0) {
			//static_assert(div != 0);
			return;
		}
		this->posX /= div;
		this->posY /= div;
		this->posZ /= div;
	}

	void operator()(const CPoint<T>& p) {
		*this = p;
	}



};

template <class T>
class CPoint<T*> {
private:
	explicit CPoint(void) = delete;
	explicit CPoint(const T, const T, const T) = delete;
	explicit CPoint(const CPoint<T>&) = delete;
public:

};

