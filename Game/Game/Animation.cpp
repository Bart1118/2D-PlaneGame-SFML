#include "Animation.h"
Animation::Animation() : mDuration(sf::milliseconds(650)), mRepeat(false), mCurrentFrame(0)
{

}
Animation::Animation(sf::Time dt)
{
	mDuration = dt;
}
Animation::~Animation()
{

}
void Animation::Load(std::string filename, std::size_t numframes)
{
	mNumFrames = numframes;
	if (_image.loadFromFile(filename) == false)
	{
		_filename = "";
		_isLoaded = false;
	}
	else
	{
		_filename = filename;
		_sprite.setTexture(_image, true);
		_isLoaded = true;
	}
}
void Animation::setFramesize(sf::Vector2i framesize)
{
	mFrameSize = framesize;
}
void Animation::Update(float elapsedTime)
{
	sf::Time timePerFrame = mDuration / static_cast<float>
		(mNumFrames);
	mElapsedTime += sf::seconds(elapsedTime);
	sf::Vector2i textureBounds(_sprite.getTexture()->getSize());
	sf::IntRect textureRect = _sprite.getTextureRect();
	if (mCurrentFrame == 0)
		textureRect = sf::IntRect(0, 0, mFrameSize.x, mFrameSize.y);
	while (mElapsedTime >= timePerFrame && (mCurrentFrame <=
		mNumFrames || mRepeat))
	{
		textureRect.left += textureRect.width;
		if (textureRect.left + textureRect.width > textureBounds.x)
		{
			textureRect.left = 0;
			textureRect.top += textureRect.height;
		}
		mElapsedTime -= timePerFrame;
		if (mRepeat)
		{
			mCurrentFrame = (mCurrentFrame + 1) % mNumFrames;
			if (mCurrentFrame == 0)
				textureRect = sf::IntRect(0, 0, mFrameSize.x,
				mFrameSize.y);
		}
		else
		{
			mCurrentFrame++;
		}
   }
	_sprite.setTextureRect(textureRect);
}