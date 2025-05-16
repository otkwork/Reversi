#pragma once

class Lerp
{
private:
	static float(*m_funcTable[])(float);	// �֐��|�C���^�z��

	template <typename T>
	static T _Exec(T begin, T end, float rate)
	{
		return static_cast<T>(begin * (1.0f - rate) + end * rate);
	}

	static float Linear(float t);
	static float EaseInOutQuad(float t);

public:
	enum class Model
	{
		Linear,
		EaseInOutQuad,
	};

	template <typename T>
	static T Exec(T begin, T end, float t, Model model = Model::Linear)
	{
		float rate = (*m_funcTable[static_cast<int>(model)])(t);
		return _Exec(begin, end, rate);
	}
};
