#include "ButtonOpeningSkip.h"
#include "ClientHeaders.h"

ButtonOpeningSkip::ButtonOpeningSkip(ManagerSet* _managers)
	:Button(_managers)
{

}

ButtonOpeningSkip::~ButtonOpeningSkip()
{

}

void ButtonOpeningSkip::OnButtonClicked()
{
	SoundManager::GetInstance()->Play(SoundManager::MOUSEEFFECT, SoundManager::BUTTON);
	SceneManager* sceneManager = GetManagers()->GetSceneManager();
	sceneManager->ChangeScene("TutorialScene");
}

void ButtonOpeningSkip::Render(GraphicsEngine* _graphicsEngine)
{
	// 여기에 버튼 이미지 넣기
	_graphicsEngine->DrawSprite("skipbtn", 98, 1500, 100, 120, 40);
	// rm->LoadImage("skipbtn", pm->GetResourcePath(L"ui\\cutscene\\Opening_btn.png"));//98
}

void ButtonOpeningSkip::DebugRender(GraphicsEngine* _graphicsEngine)
{
	// 글자색 / 글자 크기 / 글자 위치 설정
	// Button에서 protected로 text / position / size를 받아옴
	std::string renderText = text;
	_graphicsEngine->ColorSet(D2D1::ColorF::Black);
	_graphicsEngine->ChangeFontSize(fontSize);
	_graphicsEngine->DrawString((int)stringPosition.x, (int)stringPosition.y, renderText);
	_graphicsEngine->ChangeFontSize(12.f);
}
