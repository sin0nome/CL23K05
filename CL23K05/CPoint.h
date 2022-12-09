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
	* @brief 座標を表示する
	*/
	void ShowPosition(void) {
		std::cout << "X座標: " << this->posX << std::endl;
		std::cout << "Y座標: " << this->posY << std::endl;
		std::cout << "Z座標: " << this->posZ << std::endl;
		std::cout << std::endl;
	}

	/**
	* @brief 2点間の座標の差を表示する
	* @param p 距離を測定する為のもう一つの座標(CPointクラス)
	*/
	void getDistance(const CPoint<T>& p) {
		const T diffX = this->posX - p.posX;
		const T diffY = this->posY - p.posY;
		const T diffZ = this->posZ - p.posZ;

		std::cout << "1点目のX座標: " << this->posX << "\t2点目のX座標: " << p.posX << "\t差: " << diffX << std::endl;
		std::cout << "1点目のY座標: " << this->posY << "\t2点目のY座標: " << p.posY << "\t差: " << diffY << std::endl;
		std::cout << "1点目のZ座標: " << this->posZ << "\t2点目のZ座標: " << p.posZ << "\t差: " << diffZ << std::endl;

		const T diff = sqrt(diffX * diffX + diffY * diffY + diffZ * diffZ);
		std::cout << "距離: " << diff << std::endl;
		std::cout << std::endl;
	}

	/**
	* @brief 指定した時間だけ自由落下させる
	*		また指定した時間と座標を表示する
	* @param milliSecond 自由落下する時間(ms)
	* @param gravitationalAcceleration 重力加速度(初期値 9.80665f)
	*/
	void freeFall(const float milliSecond, const float gravitationalAcceleration = 9.80665f) {
		const T prePosY = this->posY;
		const float t = milliSecond / 1000.0f;
		this->posY -= 0.5f * gravitationalAcceleration * t * t;
		std::cout << "落下した時間: " << milliSecond << "ms" << std::endl;
		std::cout << "落下した距離: " << prePosY - this->posY << std::endl;
		std::cout << std::endl;
	}

	/**
	* @brief 指定した初速で真上に投げた場合、重力落下を加え座標を移動させる
	*		また指定した時間時の座標と速度を表示する
	* @param milliSecond 座標と速度を取得する時間(ms)
	* @param initialVelocity 初速
	* @param gravitationalAcceleration 重力加速度(初期値 9.80665f)
	*/
	void verticalThrowUp(const float milliSecond, const float initialVelocity, const float gravitationalAcceleration = 9.80665f) {
		const T prePosY = this->posY;
		const float t = milliSecond / 1000.0f;
		const auto add = (initialVelocity * t) - (0.5f * gravitationalAcceleration * t * t);
		const auto vel = initialVelocity + gravitationalAcceleration * t;
		this->posY += add;
		std::cout << "初速: " << initialVelocity << "m/s" << std::endl;
		std::cout << "時間: " << milliSecond << "ms" << std::endl;
		std::cout << "距離: " << add << std::endl;
		std::cout << "速度: " << vel << std::endl;
		std::cout << std::endl;
	}

	// 以下operator関連

	/**
	* @brief 座標を代入する
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

