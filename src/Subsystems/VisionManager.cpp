#include "VisionManager.h"

VisionManager::VisionManager() :
	frc::Subsystem("Vision Manager")
{
}

VisionManager::~VisionManager()
{
	delete m_vision;
	delete m_visionThread;
}

void VisionManager::InitDefaultCommand()
{
}

void VisionManager::Initialize(frc::Preferences* prefs)
{
	m_cs = frc::CameraServer::GetInstance();

	m_cam = m_cs->StartAutomaticCapture(CS_CAM_PEG_PORT);
	m_cam.SetResolution(640, 480);
	m_cam.SetFPS(CS_CAM_FPS_DEFAULT);

	//cs::CvSink sink = frc::CameraServer::GetInstance()->GetVideo();
	//cv::Mat mat;

	m_vision = new frc::VisionRunner<grip::GripPipeline>(
			m_cam,
			new grip::GripPipeline(),
			[&](grip::GripPipeline& pipeline)
			{
				//pipeline.Process(mat);
				//grip::CameraStuff camstuff = grip::CameraStuff();
				pipeline.setStuff(PEG);
				//frc::SmartDashboard::PutBoolean("Getting Target", pipeline.getTarget());
				frc::SmartDashboard::PutNumber("CenterX", pipeline.getTargetCenterX(0));
				frc::SmartDashboard::PutNumber("Processing Time", pipeline.getProcTime());
				frc::SmartDashboard::PutNumber("Targets", pipeline.getTargets());
			});
	m_lock = new std::mutex();
}

void VisionManager::DashboardOutput(bool verbose)
{
	m_lock->lock();
	frc::SmartDashboard::PutBoolean("Vision Processing Running", m_isRunning);
	m_lock->unlock();

	if (verbose)
	{

	}
}

void VisionManager::vision_thread()
{
	while (true)
	{
		m_vision->RunOnce();

		m_lock->lock();
		if (!m_isRunning)
		{
			m_lock->unlock();
			break;
		}
		m_lock->unlock();
		sleep(20);
	}
}

void VisionManager::StartProc()
{
	m_isRunning = true;
	m_visionThread = new std::thread(&VisionManager::vision_thread, this);
	m_visionThread->detach();
}
