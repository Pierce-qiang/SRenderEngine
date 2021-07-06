#include "./Scene.h"

#include "./graphics/texture/TextureLoader.h"
#include "./graphics/model/shapes/Cube.h"
#include "./graphics/model/shapes/Sphere.h"

namespace sre 
{
	Scene::Scene(int sceneID):
		mCamera(new Camera()),
		mModelRenderer(new ModelRenderer(mCamera))
	{
		

		Init(sceneID);
	}
	Scene::~Scene()
	{
		delete mCamera;
	}

	void Scene::Update(float deltaTime)
	{
		// just process the user's input now
		mCamera->ProcessInput(deltaTime);
	}

	void Scene::AddModelsToRender()
	{
		// add all models to renderer's render queue
		for (auto it : mModels)
			mModelRenderer->SubmitRenderModel(it);
		
	}

	void Scene::Init(int sceneID)
	{
		// TODO: initialize model to mModels according to sceneID

		Model *cube1 = new Model(Cube());
		Model *cube2 = new Model(Cube());
		Model *cube3 = new Model(Cube());
		mModels.push_back(cube1);
		mModels.push_back(cube2);
		mModels.push_back(cube3);
		//Model* sphere1 = new Model(Sphere());
		//Model* sphere2 = new Model(Sphere());
		//mModels.push_back(sphere1);
		//mModels.push_back(sphere2);

		cube1->SetPosition(glm::vec3(0.0f, 0.0f, 0.0f));
		cube1->SetScale(glm::vec3(1.0f, 1.0f, 1.0f));
		cube2->SetPosition(glm::vec3(0.0f, -2.0f, 0.0f));
		cube2->SetScale(glm::vec3(30.0f, 1.0f, 30.0f));
		cube3->SetPosition(glm::vec3(1.0f, 3.0f, 1.0f));
		cube3->SetScale(glm::vec3(2.0f, 2.0f, 2.0f));

		TextureSettings srgbTextureSettings;
		srgbTextureSettings.IsSRGB = true;
		cube1->GetMesh(0)->GetMaterial()->SetAlbedoMap(TextureLoader::Load2DTexture("res/texture/wood.png", &srgbTextureSettings));
		cube2->GetMesh(0)->GetMaterial()->SetAlbedoMap(TextureLoader::Load2DTexture("res/texture/wood.png", &srgbTextureSettings));
		cube3->GetMesh(0)->GetMaterial()->SetAlbedoMap(TextureLoader::Load2DTexture("res/texture/wood.png", &srgbTextureSettings));

		

	}
}