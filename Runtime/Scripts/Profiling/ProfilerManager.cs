using Unity.WebRTC.Runtime.Profiling;
using UnityEngine;

public class ProfilerManager : MonoBehaviour
{
    // Update is called once per frame
    void Update()
    {
        int value = (int)(Mathf.Sin(Time.time) * 10);
        Stats.BulletCount.Value = value;
        Stats.BulletCount.Sample();

        Stats.EnemyCount.Sample(Mathf.Sin(Time.time) * 10);
    }
}
